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

/* The type of container used to hold the state vector */
typedef std::vector< double > state_type;

class Simulation
{
public:
    Simulation(Settings* settings);

    std::vector<Factor*> factors;

    void simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps);

private:
    Settings *settings;
    void setFactors();

};

class Model
{
public:
    Model(std::vector<Factor*> _factors, double _roomVolume)
    {
        factors = _factors;
        roomValue = _roomVolume;
    }
    void operator()( const state_type &x , state_type &dxdt , const double /* t */ )
    {
            double sumTemp=0, sumCO2=0, sumHumidity=0;
            for (int i = 0; i < this->factors.size(); i++)
            {
                sumTemp += this->factors[i]->changeTemperature(x[0], this->roomValue);
                sumCO2 += this->factors[i]->changeCO2();
                sumHumidity += this->factors[i]->changeHumidity(x[2], this->roomValue);
            }

            dxdt[0] = sumTemp;     // temperature
            dxdt[1] = sumCO2;     // CO2
            dxdt[2] = sumHumidity;     // humidity
    }
private:
    std::vector<Factor*> factors;
    double roomValue;
};

struct observer
{
    std::vector<state_type>& states;
    std::vector<double>& times;

    observer(std::vector<state_type>& x, std::vector<double>& t)
        :   states(x), times(t) {}

    void operator() (const state_type& x, double t)
    {
        states.push_back(x);
        times.push_back(t);
    }
};

#endif // SIMULATION_H
