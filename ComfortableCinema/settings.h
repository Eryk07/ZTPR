#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    int rooms;
    int fansCount=3;
    double simulationTime;
    int simulationStep;

private slots:
    void on_spinFansCount_valueChanged(int _fansCount);

    void on_spinRooms_valueChanged(int _rooms);

    void on_doubleSpinSimTime_valueChanged(double _simTime);

    void on_simulationStepSpinBox_valueChanged(int _simStep);

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
