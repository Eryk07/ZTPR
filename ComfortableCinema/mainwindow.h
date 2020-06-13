#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <vector>

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
    void on_toolButton_clicked();
    void makePlot(QCustomPlot* plot, QVector<double> x, QVector<double> y);
    void on_pushButton_clicked();

private:
    Cinema* cinema;
    std::vector<Conditions> currentRoomConditions;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
