#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{

    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}



void Settings::on_spinRooms_valueChanged(int _rooms)
{
    rooms = _rooms;
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
