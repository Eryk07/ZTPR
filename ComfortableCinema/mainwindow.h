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

/** Class of main window application */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_settingsButton_clicked();
    void on_simulationButton_clicked();

private:
    /// Pointer to cinema object
    Cinema* cinema;
    /// Pointer to settings
    Settings* settings;
    /// Vector of conditions in current room
    std::vector<Conditions> currentRoomConditions;
    /// Pointer to ui dialog
    Ui::MainWindow *ui;

    /**
     * Make plot in main window
     * @param plot pointer to plot
     * @param x vector of X axis
     * @param y vector of Y axis
     * @param plotType specifier of each plot type: 1 - temperature, 2 - humidity, 3 - CO2
     */
    void makePlot(QCustomPlot* plot, QVector<double> x, QVector<double> y, int plotType);
};
#endif // MAINWINDOW_H
