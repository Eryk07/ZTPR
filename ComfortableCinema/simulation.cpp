#include "simulation.h"

Simulation::Simulation()
{
    this->setFactors();
}

void Simulation::setFactors()
{
    int peopleCount = 10; // domyślnie połączenie z PeopleManager ze ScreeningRoom
    int fansCount = 4; // domyślnie połączenie z Settings

    this->factors.clear();
    this->factors.push_back(new AirConditioning(fansCount));
    this->factors.push_back(new People(peopleCount));
}

void Simulation::model( const state_type &x , state_type &dxdt , const double /* t */ )
{
        //tu dodać połączenie z wektorem Factor i poszczególnymi changerami
        dxdt[0] = 2*x[1];
        dxdt[1] = x[2]-x[0];
        dxdt[2] = x[2];
}

void Simulation::simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps)
{
    state_type initX(3);
    initX[0] = 10000.0;     // inity z settingsów
    initX[1] = 100;
    initX[2] = 100;
    std::vector<state_type>    states;
    std::vector<double>         times;
    Conditions momentCondition;

    size_t steps = odeint::integrate(model,
            initX , 0.0 , 10.0 , 0.1, observer(states, times));     // czas, kroki z settingsów

    for( size_t i=0; i<=steps; i++ )
    {
        momentCondition.temperature = states[i][0];
        momentCondition.CO2 = states[i][1];
        momentCondition.humidity = states[i][2];

        roomConditions.push_back(momentCondition);
    }

    roomTimesteps = QVector<double>(times.begin(), times.end());

}
