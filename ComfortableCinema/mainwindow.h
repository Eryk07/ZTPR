#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <vector>
#include <algorithm>

#include "cinema.h"
#include "factors/conditions.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Settings* settings;

private slots:
    void on_settingsButton_clicked();
    void update();
    void on_simulationButton_clicked();

private:
    Cinema* cinema;
    std::vector<Conditions> currentRoomConditions;
    Ui::MainWindow *ui;
    QTimer* timer;
    double counter;
    void drawSimulation();
    void makePlot(QCustomPlot* plot, QVector<double> x, QVector<double> y, int plotType);
};
#endif // MAINWINDOW_H
