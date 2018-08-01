#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <OpenNI.h>
#include "myplayeroni.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MyPlayerONI mp_oni;
    QTimer* image_updater;
    bool playFlag = false;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Button_NextFrame_clicked();

    void imageUpdate();

    void timerImageUpdate();

    void on_horizontalSlider_sliderReleased();

    void on_Button_PreviousFrame_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_Button_PlayPause_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
