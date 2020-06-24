#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    settings = new Settings();
    cinema = new Cinema(settings);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settingsButton_clicked()
{
    settings->show();
}

void MainWindow::on_simulationButton_clicked()
{
    this->cinema->updateRooms();
    this->currentRoomConditions = cinema ->getRoomConditions(0);
    QVector<double> times = cinema -> getRoomSimTime(0);
    QVector<double> temperature, humidity, co2;
    for (unsigned int i=0; i<this->currentRoomConditions.size(); ++i)
    {
        temperature.push_back(this->currentRoomConditions[i].temperature);
        humidity.push_back(100*this->currentRoomConditions[i].humidity);
        co2.push_back(this->currentRoomConditions[i].CO2);
    }

    makePlot(ui->tempPlot, times, temperature, 1);
    makePlot(ui->humidityPlot, times, humidity, 2);
    makePlot(ui->co2Plot, times, co2, 3);

}

void MainWindow::makePlot(QCustomPlot* plot, QVector<double> x, QVector<double> y, int plotType)
{
    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(0)->setData(x, y);
    // give the axes some labels:
    plot->xAxis->setLabel("Time [s]");
    QPen pen;
    switch (plotType)
    {
        case 1:
            plot->yAxis->setLabel("T['C]");
            pen.setWidth(1);
            pen.setColor(QColor(Qt::red));
            plot->graph(0)->setPen(pen);
            break;
        case 2:
            plot->yAxis->setLabel("H[%]");
            break;
        case 3:
            plot->yAxis->setLabel("CO2[ppm]");
            pen.setWidth(1);
            pen.setColor(QColor(Qt::green));
            plot->graph(0)->setPen(pen);
            break;
    }

    double* yMax = std::max_element(y.begin(), y.end());
    double* yMin = std::min_element(y.begin(), y.end());

    plot->xAxis->setRange(0, this->settings->getSimulationTime());
    plot->yAxis->setRange(0.9*(*yMin), 1.1*(*yMax));
    plot->replot();
}
