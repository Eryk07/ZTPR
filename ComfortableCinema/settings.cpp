#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    roomsCount = 1;
    roomVolume = 100000.0;
    peopleCount = 100;
    fansCount = 4;
    speed = 1.0;
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
    ui->spinRooms->setValue(roomsCount);
    ui->spinRooms->setRange(1, 8);

    ui->spinFansCount->setValue(fansCount);
    ui->spinFansCount->setRange(1, 4);


    ui->doubleSpinSimTime->setRange(1, 1000);
    ui->doubleSpinSimTime->setSingleStep(0.5);
    ui->doubleSpinSimTime->setDecimals(1);
    ui->doubleSpinSimTime->setValue(simulationTime);

    ui->simulationStepSpinBox->setValue(simulationStep);
    ui->simulationStepSpinBox->setRange(1, 8);


    //weather
    ui->weatherCO2doubleSpinBox->setRange(350.0, 500.0);
    ui->weatherCO2doubleSpinBox->setSingleStep(0.1);
    ui->weatherCO2doubleSpinBox->setDecimals(1);
    ui->weatherCO2doubleSpinBox->setValue(weather.CO2);

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
    ui->initCO2doubleSpinBox->setValue(initConditions.CO2);


    ui->initTempdoubleSpinBox->setSingleStep(0.1);
    ui->initTempdoubleSpinBox->setDecimals(1);
    ui->initTempdoubleSpinBox->setValue(initConditions.temperature);

    ui->initHumiditydoubleSpinBox->setRange(0, 1);
    ui->initHumiditydoubleSpinBox->setSingleStep(0.01);
    ui->initHumiditydoubleSpinBox->setValue(initConditions.humidity);
}

void Settings::on_spinRooms_valueChanged(int _rooms)
{
    roomsCount = _rooms;
}

void Settings::on_spinFansCount_valueChanged(int _fansCount)
{
    fansCount = _fansCount;
}

void Settings::on_doubleSpinSimTime_valueChanged(double _simTime)
{
    simulationTime = _simTime;
}

void Settings::on_simulationStepSpinBox_valueChanged(int _simStep)
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
