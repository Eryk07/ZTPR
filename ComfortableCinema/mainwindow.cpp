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

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    counter=0;
    timer->start(settings->simulationStep * 1000);
}

void MainWindow::update()
{
    this->counter += settings->simulationStep;
    if(this->counter >= settings->simulationTime)
        timer->stop();
    else
        drawSimulation();
}

void MainWindow::drawSimulation()
{
    QVector<double> times;

    for(auto it=cinema->getRoomSimTime(0).begin(); it!=cinema -> getRoomSimTime(0).end(); it++)
        if ((*it) < this->counter)//(this->settings->simulationTime - (this->timer->remainingTime())/1000.0))
            times.push_back((*it));

    QVector<double> temperature, humidity, co2;
    for (unsigned int i=0; i<times.size(); ++i)
    {
        temperature.push_back(this->currentRoomConditions[i].temperature);
        humidity.push_back(this->currentRoomConditions[i].humidity);
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

    double* max = std::max_element(y.begin(), y.end());
    int max_index = std::distance(y.begin(), max);

    plot->xAxis->setRange(0, this->settings->simulationTime);//x[x.size()-1]); //docelowo simtime!!
    plot->yAxis->setRange(0, 1.1*y[max_index]);
    plot->replot();
}
