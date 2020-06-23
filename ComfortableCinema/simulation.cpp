#include "simulation.h"

Simulation::Simulation(Settings *settings)
{
    this->settings = settings;
    this->setFactors();
}

void Simulation::setFactors()
{
    int peopleCount = this->settings->peopleCount; // domyślnie połączenie z PeopleManager ze ScreeningRoom

    this->factors.clear();
    this->factors.push_back(new AirConditioning(this->settings->fansCount, this->settings->fanSpeed));
    this->factors.push_back(new People(peopleCount));
}

void Simulation::simulate(std::vector<Conditions> &roomConditions, QVector<double> &roomTimesteps)
{
    state_type initX(3);
    initX[0] = settings->initConditions.temperature;     // inity z settingsów
    initX[1] = settings->initConditions.CO2;
    initX[2] = settings->initConditions.humidity;
    std::vector<state_type>    states;
    std::vector<double>         times;
    Conditions momentCondition;
    Model model(this->factors, this->settings->roomVolume);

    size_t steps = odeint::integrate(model,
            initX , 0.0 ,  this->settings->simulationTime,
            this->settings->simulationStep, observer(states, times));     // czas, kroki z settingsów

    for( size_t i=0; i<=steps; i++ )
    {
        momentCondition.temperature = states[i][0];
        momentCondition.CO2 = states[i][1];
        momentCondition.humidity = states[i][2];

        roomConditions.push_back(momentCondition);
    }

    roomTimesteps = QVector<double>(times.begin(), times.end());

}
