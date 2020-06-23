#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "factors/conditions.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    int roomsCount;
    double roomVolume;
    Conditions weather;
    int peopleCount;
    int fansCount;
    double speed;
    Conditions initConditions;
    double simulationTime;
    double simulationStep;


private slots:
    void on_spinFansCount_valueChanged(int _fansCount);

    void on_spinRooms_valueChanged(int _rooms);

    void on_doubleSpinSimTime_valueChanged(double _simTime);

    void on_simulationStepSpinBox_valueChanged(int _simStep);

    void on_weatherCO2doubleSpinBox_valueChanged(double _weatherCO2);

    void on_weatherTempdoubleSpinBox_valueChanged(double _weatherTemp);

    void on_weatherHumiditydoubleSpinBox_valueChanged(double _weatherHumidity);

    void on_initCO2doubleSpinBox_valueChanged(double _initCO2);

    void on_initTempdoubleSpinBox_valueChanged(double _initTemp);

    void on_initHumiditydoubleSpinBox_valueChanged(double _initHumidity);

private:
    Ui::Settings *ui;
    void initSpinBoxes();
};

#endif // SETTINGS_H
