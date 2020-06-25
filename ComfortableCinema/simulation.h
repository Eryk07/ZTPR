#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "boost/numeric/odeint.hpp"
#include <numeric>

#include "settings.h"
#include "factors/factor.h"
#include "factors/airconditioning.h"
#include "factors/people.h"

using namespace boost::numeric;

/** The type of container used to hold the state vector */
typedef std::vector< double > state_type;

/** Class responsible for simulating cinema conditions, using Factors and boost solver */
class Simulation
{
public:
    /** Constructor of Simulation class
    * @param *settings pointer to settings object from MainWindow class
    * */
    Simulation(Settings* settings);
    /** Function for simulating
     * @param &roomConditions vector of conditions in screening room
     * @param &roomTimesteps vector of timesteps of simulation
     * */
    void simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps);

private:
    /// Pointer to settings object from MainWindow class
    Settings *settings;
    /// Vector of factors used for simulation purpose
    std::vector<Factor*> factors;
    void setFactors();

};

/** Class responsible for model used in simulation, prepared to used with boost solver */
class Model
{
public:
    /** Constructor of Model class
    * @param *_factors pointer to vector of factors used by simulation
    * @param _roomVolume used
    * */
    Model(std::vector<Factor*> _factors, double _roomVolume)
    {
        factors = _factors;
        roomVolume = _roomVolume;
    }

    /** Operator () of Model class
    * @param &x state vector of model
    * @param &dxdt derivative of the state vector
    * */
    void operator()( const state_type &x , state_type &dxdt , const double /* t */ )
    {
            double sumTemp=0, sumCO2=0, sumHumidity=0;
            for (int i = 0; i < this->factors.size(); i++)
            {
                sumTemp += this->factors[i]->changeTemperature(x[0], this->roomVolume);
                sumCO2 += this->factors[i]->changeCO2();
                sumHumidity += this->factors[i]->changeHumidity(x[2], this->roomVolume);
            }

            dxdt[0] = sumTemp;     // temperature
            dxdt[1] = sumCO2;     // CO2
            dxdt[2] = sumHumidity;     // humidity
    }
private:
    /// Vector of factors used for model feed purpose
    std::vector<Factor*> factors;
    /// Volume of room used for model feed purpose
    double roomVolume;
};

/** Structure create to use with boost model */
struct Observer
{
    /// States calculated by model
    std::vector<state_type>& states;
    /// Times of each states calculated by model
    std::vector<double>& times;

    /// Constructor of observer used to fill states and each times
    Observer(std::vector<state_type>& x, std::vector<double>& t)
        :   states(x), times(t) {}

    /** Operator () of observer structure
    * @param &x state vector of model
    * @param &t times of each states
    * */
    void operator() (const state_type& x, double t)
    {
        states.push_back(x);
        times.push_back(t);
    }
};

#endif // SIMULATION_H
