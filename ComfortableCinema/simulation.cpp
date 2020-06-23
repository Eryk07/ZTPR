#include "simulation.h"

Simulation::Simulation()
{
    this->setFactors();
}

void Simulation::setFactors()
{
    int peopleCount = 100; // domyślnie połączenie z PeopleManager ze ScreeningRoom
    int fansCount = 4; // domyślnie połączenie z Settings
    double initSpeed = 0.5; // domyślnie połączenie z Settings

    this->factors.clear();
    this->factors.push_back(new AirConditioning(fansCount, initSpeed));
    this->factors.push_back(new People(peopleCount));
}

void Simulation::simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps)
{
    state_type initX(3);
    initX[0] = 20.0;     // inity z settingsów
    initX[1] = 410;
    initX[2] = 0.65;
    std::vector<state_type>    states;
    std::vector<double>         times;
    Conditions momentCondition;
    double roomVolume = 100000.0; // domyślnie z Settings
    Model model(this->factors, roomVolume);

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
