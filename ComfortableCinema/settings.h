#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "factors/conditions.h"

namespace Ui {
class Settings;
}

/** Class used for setting params of simulation */
class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    int getRoomsCount() const;
    /** Setter of rooms count
    * @param value must be higher than 0
    * */
    void setRoomsCount(int value);

    double getRoomVolume() const;
    /** Setter of room volume
    * @param value must be higher than 0
    * */
    void setRoomVolume(double value);

    Conditions getWeather() const;
    /** Setter of weather conditions
    * @param value.CO2 and value.humidity must be higher than 0
    * */
    void setWeather(const Conditions &value);

    int getPeopleCount() const;
    /** Setter of people count
    * @param value must be higher than 0
    * */
    void setPeopleCount(int value);

    int getFansCount() const;

    double getFanSpeed() const;
    /** Setter of fan speed
    * @param value must be higher than 0
    * */
    void setFanSpeed(double value);

    Conditions getInitConditions() const;
    /** Setter of init conditions
    * @param value.CO2 and value.humidity must be higher than 0
    * */
    void setInitConditions(const Conditions &value);

    double getSimulationTime() const;
    /** Setter of simulation time
    * @param value must be higher than 0
    * */
    void setSimulationTime(double value);

    double getSimulationStep() const;
    /** Setter of simulation step
    * @param value must be higher than 0
    * */
    void setSimulationStep(double value);

private slots:

    void on_fansCountSpinBox_valueChanged(int _fansCount);

    void on_fanSpeedDoubleSpinBox_valueChanged(double _fanSpeed);

    void on_roomsCountSpinBox_valueChanged(int _roomsCount);

    void on_roomVolumeDoubleSpinBox_valueChanged(double _roomVolume);

    void on_peopleCountSpinBox_valueChanged(int _peopleCount);

    void on_simulationTimeDoubleSpinBox_valueChanged(double _simTime);

    void on_simulationStepDoubleSpinBox_valueChanged(double _simStep);

    void on_weatherCO2doubleSpinBox_valueChanged(double _weatherCO2);

    void on_weatherTempdoubleSpinBox_valueChanged(double _weatherTemp);

    void on_weatherHumiditydoubleSpinBox_valueChanged(double _weatherHumidity);

    void on_initCO2doubleSpinBox_valueChanged(double _initCO2);

    void on_initTempdoubleSpinBox_valueChanged(double _initTemp);

    void on_initHumiditydoubleSpinBox_valueChanged(double _initHumidity);

private:
    /// pointer to dialog window of settings
    Ui::Settings *ui;
    /// number of rooms in cinema
    int roomsCount;
    /// volume of room
    double roomVolume;
    /// conditions of weather outside cinema
    Conditions weather;
    /// number of people in room
    int peopleCount;
    /// number of fans in rooms
    int fansCount;
    /// speed of fans in room
    double fanSpeed;
    /// init conditions in room
    Conditions initConditions;
    /// time of simulation
    double simulationTime;
    /// step of simulation time
    double simulationStep;

    /// init of default values, range of spinboxes in settings
    void initSpinBoxes();
};

#endif // SETTINGS_H
