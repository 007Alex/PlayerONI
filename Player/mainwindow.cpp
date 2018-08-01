#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    image_updater = new QTimer(this);
    connect(image_updater,SIGNAL(timeout()), this, SLOT(timerImageUpdate()));
}

MainWindow::~MainWindow()
{
    mp_oni.~MyPlayerONI();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->Lable_Pixmap->clear();
    ui->Lable_Pixmap2->clear();
    QString filename = QFileDialog::getOpenFileName(this,"Open a file","","ONI file (*.oni)");
    if(filename != "")
    {
        if(playFlag == true)
            on_Button_PlayPause_clicked();

        mp_oni.LoadFile(filename);

        if(mp_oni.isValid()){
            ui->horizontalSlider->setMaximum(mp_oni.getFrameCount());
            imageUpdate();
            ui->Button_PlayPause->setEnabled(true);
            ui->Button_NextFrame->setEnabled(true);
            ui->Button_PreviousFrame->setEnabled(true);
        }
        else{
            ui->horizontalSlider->setMaximum(1);
            ui->Button_PlayPause->setEnabled(false);
            ui->Button_NextFrame->setEnabled(false);
            ui->Button_PreviousFrame->setEnabled(false);
        }
    }
    ui->FilenameLabel->setText(filename);
}

void MainWindow::imageUpdate(){
    ui->Lable_Pixmap->clear();
    ui->Lable_Pixmap2->clear();
    ui->Lable_Pixmap->setPixmap(QPixmap::fromImage(mp_oni.getColorFrameImage()));
    ui->Lable_Pixmap2->setPixmap(QPixmap::fromImage(mp_oni.getDepthFrameImage()));
    ui->horizontalSlider->setValue(mp_oni.getCurentFrameIndex());

    ui->label->setText(std::to_string(mp_oni.getCurentFrameIndex()).c_str());
}

void MainWindow::timerImageUpdate(){
    mp_oni.NextFrame();
    imageUpdate();
}

void MainWindow::on_Button_NextFrame_clicked()
{
    mp_oni.NextFrame();
    imageUpdate();
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    int k = ui->horizontalSlider->value();
    mp_oni.setFrameIndex(k);
    imageUpdate();
}

void MainWindow::on_Button_PreviousFrame_clicked()
{
    mp_oni.setFrameIndex(mp_oni.getCurentFrameIndex()-1);
    imageUpdate();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

    ui->label->setText(std::to_string(value).c_str());
}

void MainWindow::on_Button_PlayPause_clicked()
{
    if(playFlag == false){
        playFlag = true;
        ui->Button_NextFrame->setEnabled(false);
        ui->Button_PreviousFrame->setEnabled(false);
        image_updater->start((int)(1000/mp_oni.fps));
        mp_oni.play();
    }
    else{
        playFlag = false;
        ui->Button_NextFrame->setEnabled(true);
        ui->Button_PreviousFrame->setEnabled(true);
        image_updater->stop();
        mp_oni.pause();
    }
}
