#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    roomsCount = 1;
    roomVolume = 1000.0;
    peopleCount = 100;
    fansCount = 4;
    fanSpeed = 1.0;
    simulationTime = 300.0;
    simulationStep = 1.0;

    weather.CO2 = 415.5;
    weather.temperature = 20.5;
    weather.humidity = 0.6;

    initConditions.CO2 = 415.5;
    initConditions.temperature = 18.0;
    initConditions.humidity = 0.5;

    ui->setupUi(this);
    initSpinBoxes();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::initSpinBoxes()
{
    // general
    ui->roomsCountSpinBox->setValue(roomsCount);
    ui->roomsCountSpinBox->setRange(1, 8);

    ui->roomVolumeDoubleSpinBox->setRange(500, 6000);
    ui->roomVolumeDoubleSpinBox->setSingleStep(0.5);
    ui->roomVolumeDoubleSpinBox->setDecimals(1);
    ui->roomVolumeDoubleSpinBox->setValue(1000);

    ui->peopleCountSpinBox->setValue(peopleCount);
    ui->peopleCountSpinBox->setRange(1, 300);

    ui->fanSpeedDoubleSpinBox->setRange(0, 5);
    ui->fanSpeedDoubleSpinBox->setSingleStep(0.1);
    ui->fanSpeedDoubleSpinBox->setDecimals(1);
    ui->fanSpeedDoubleSpinBox->setValue(fanSpeed);

    ui->fansCountSpinBox->setValue(fansCount);
    ui->fansCountSpinBox->setRange(0, 4);

    ui->simulationTimeDoubleSpinBox->setRange(1, 2000);
    ui->simulationTimeDoubleSpinBox->setSingleStep(0.5);
    ui->simulationTimeDoubleSpinBox->setDecimals(1);
    ui->simulationTimeDoubleSpinBox->setValue(300.0);

    ui->simulationStepDoubleSpinBox->setRange(1, 60);
    ui->simulationStepDoubleSpinBox->setSingleStep(0.5);
    ui->simulationStepDoubleSpinBox->setDecimals(1);
    ui->simulationStepDoubleSpinBox->setValue(simulationStep);

    //weather
    ui->weatherCO2doubleSpinBox->setRange(350.0, 500.0);
    ui->weatherCO2doubleSpinBox->setSingleStep(0.1);
    ui->weatherCO2doubleSpinBox->setDecimals(1);
    ui->weatherCO2doubleSpinBox->setValue(415.5);

    ui->weatherTempdoubleSpinBox->setSingleStep(0.1);
    ui->weatherTempdoubleSpinBox->setDecimals(1);
    ui->weatherTempdoubleSpinBox->setValue(weather.temperature);

    ui->weatherHumiditydoubleSpinBox->setRange(0, 1);
    ui->weatherHumiditydoubleSpinBox->setSingleStep(0.01);
    ui->weatherHumiditydoubleSpinBox->setValue(weather.humidity);

    //init inside conditions

    ui->initCO2doubleSpinBox->setRange(350.0, 500.0);
    ui->initCO2doubleSpinBox->setSingleStep(0.1);
    ui->initCO2doubleSpinBox->setDecimals(1);
    ui->initCO2doubleSpinBox->setValue(415.5);

    ui->initTempdoubleSpinBox->setSingleStep(0.1);
    ui->initTempdoubleSpinBox->setDecimals(1);
    ui->initTempdoubleSpinBox->setValue(initConditions.temperature);

    ui->initHumiditydoubleSpinBox->setRange(0, 1);
    ui->initHumiditydoubleSpinBox->setSingleStep(0.01);
    ui->initHumiditydoubleSpinBox->setValue(initConditions.humidity);
}

double Settings::getSimulationStep() const
{
    return simulationStep;
}

void Settings::setSimulationStep(double value)
{
    if (value > 0)
        simulationStep = value;
}

double Settings::getSimulationTime() const
{
    return simulationTime;
}

void Settings::setSimulationTime(double value)
{
    if (value > 0)
        simulationTime = value;
}

Conditions Settings::getInitConditions() const
{
    return initConditions;
}

void Settings::setInitConditions(const Conditions &value)
{
    if (value.CO2 > 0 && value.humidity > 0)
        initConditions = value;
}

double Settings::getFanSpeed() const
{
    return fanSpeed;
}

void Settings::setFanSpeed(double value)
{
    if (value >= 0)
        fanSpeed = value;
}

int Settings::getFansCount() const
{
    return fansCount;
}

int Settings::getPeopleCount() const
{
    return peopleCount;
}

void Settings::setPeopleCount(int value)
{
    if (value >= 0)
        peopleCount = value;
}

Conditions Settings::getWeather() const
{
    return weather;
}

void Settings::setWeather(const Conditions &value)
{
    if (value.CO2 > 0 && value.humidity > 0)
        weather = value;
}

double Settings::getRoomVolume() const
{
    return roomVolume;
}

void Settings::setRoomVolume(double value)
{
    if (value > 0)
        roomVolume = value;
}

int Settings::getRoomsCount() const
{
    return roomsCount;
}

void Settings::setRoomsCount(int value)
{
    if (value > 0)
        roomsCount = value;
}

void Settings::on_fansCountSpinBox_valueChanged(int _fansCount)
{
    fansCount = _fansCount;
}

void Settings::on_fanSpeedDoubleSpinBox_valueChanged(double _fanSpeed)
{
    fanSpeed = _fanSpeed;
}

void Settings::on_roomsCountSpinBox_valueChanged(int _roomsCount)
{
    roomsCount = _roomsCount;
}

void Settings::on_roomVolumeDoubleSpinBox_valueChanged(double _roomVolume)
{
    roomVolume = _roomVolume;
}

void Settings::on_peopleCountSpinBox_valueChanged(int _peopleCount)
{
    peopleCount = _peopleCount;
}

void Settings::on_simulationTimeDoubleSpinBox_valueChanged(double _simTime)
{
    simulationTime = _simTime;
}

void Settings::on_simulationStepDoubleSpinBox_valueChanged(double _simStep)
{
    simulationStep = _simStep;
}

void Settings::on_weatherCO2doubleSpinBox_valueChanged(double _weatherCO2)
{
    weather.CO2 = _weatherCO2;
}

void Settings::on_weatherTempdoubleSpinBox_valueChanged(double _weatherTemp)
{
    weather.temperature = _weatherTemp;
}

void Settings::on_weatherHumiditydoubleSpinBox_valueChanged(double _weatherHumidity)
{
    weather.humidity = _weatherHumidity;
}

void Settings::on_initCO2doubleSpinBox_valueChanged(double _initCO2)
{
    initConditions.CO2 = _initCO2;
}

void Settings::on_initTempdoubleSpinBox_valueChanged(double _initTemp)
{
    initConditions.temperature = _initTemp;
}

void Settings::on_initHumiditydoubleSpinBox_valueChanged(double _initHumidity)
{
    initConditions.humidity = _initHumidity;
}
