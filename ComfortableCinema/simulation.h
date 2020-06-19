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
    Simulation();

    Settings* settings;
    std::vector<Factor*> factors;

    void simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps);

private:
    void setFactors();
    static void model(const state_type &x , state_type &dxdt, const double /* t */);

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
