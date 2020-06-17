#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cinema = new Cinema();
    ui->setupUi(this);
    settings = new Settings();

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
    // generate some data:                                              //TU ZROBIĆ TEMPLATE???
    QVector<double> x(1001); // initialize with entries 0..1000
//    for (int i=0; i<100; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }
    QVector<double> tmp(1001);
    for (unsigned int i=0; i<this->currentRoomConditions.size(); ++i)
    {
        x[i] = i;
        tmp[i] = this->currentRoomConditions[i].temperature;
    }

    makePlot(ui->tempPlot, x, tmp);
    makePlot(ui->humidityPlot, x, tmp);
    makePlot(ui->co2Plot, x, tmp);

}

void MainWindow::makePlot(QCustomPlot* plot, QVector<double> x, QVector<double> y)
{
    // create graph and assign data to it:
    plot->addGraph();
    plot->graph(0)->setData(x, y);
    // give the axes some labels:
    plot->xAxis->setLabel("x");
    plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    plot->xAxis->setRange(0, 1000); //docelowo simtime!!
    plot->yAxis->setRange(0, 600000); // docelowo 1.1*max wektora
    plot->replot();
}
