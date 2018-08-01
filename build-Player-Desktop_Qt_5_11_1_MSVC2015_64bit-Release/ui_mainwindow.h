/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *FilenameLabel;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *Button_PlayPause;
    QPushButton *Button_NextFrame;
    QPushButton *Button_PreviousFrame;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *Lable_Pixmap;
    QLabel *Lable_Pixmap2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(509, 451);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        FilenameLabel = new QLabel(centralWidget);
        FilenameLabel->setObjectName(QStringLiteral("FilenameLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilenameLabel->sizePolicy().hasHeightForWidth());
        FilenameLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(FilenameLabel, 1, 1, 1, 5);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(1);
        horizontalSlider->setPageStep(0);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 5, 0, 1, 6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        Button_PlayPause = new QPushButton(centralWidget);
        Button_PlayPause->setObjectName(QStringLiteral("Button_PlayPause"));
        Button_PlayPause->setEnabled(false);

        gridLayout->addWidget(Button_PlayPause, 6, 2, 1, 2);

        Button_NextFrame = new QPushButton(centralWidget);
        Button_NextFrame->setObjectName(QStringLiteral("Button_NextFrame"));
        Button_NextFrame->setEnabled(false);
        sizePolicy1.setHeightForWidth(Button_NextFrame->sizePolicy().hasHeightForWidth());
        Button_NextFrame->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Button_NextFrame, 6, 5, 1, 1);

        Button_PreviousFrame = new QPushButton(centralWidget);
        Button_PreviousFrame->setObjectName(QStringLiteral("Button_PreviousFrame"));
        Button_PreviousFrame->setEnabled(false);
        sizePolicy1.setHeightForWidth(Button_PreviousFrame->sizePolicy().hasHeightForWidth());
        Button_PreviousFrame->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Button_PreviousFrame, 6, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Lable_Pixmap = new QLabel(centralWidget);
        Lable_Pixmap->setObjectName(QStringLiteral("Lable_Pixmap"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Lable_Pixmap->sizePolicy().hasHeightForWidth());
        Lable_Pixmap->setSizePolicy(sizePolicy2);
        Lable_Pixmap->setAutoFillBackground(false);
        Lable_Pixmap->setFrameShadow(QFrame::Raised);
        Lable_Pixmap->setScaledContents(true);
        Lable_Pixmap->setAlignment(Qt::AlignCenter);
        Lable_Pixmap->setMargin(0);

        horizontalLayout->addWidget(Lable_Pixmap);

        Lable_Pixmap2 = new QLabel(centralWidget);
        Lable_Pixmap2->setObjectName(QStringLiteral("Lable_Pixmap2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Lable_Pixmap2->sizePolicy().hasHeightForWidth());
        Lable_Pixmap2->setSizePolicy(sizePolicy3);
        Lable_Pixmap2->setFrameShadow(QFrame::Raised);
        Lable_Pixmap2->setScaledContents(true);
        Lable_Pixmap2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(Lable_Pixmap2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 6);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        FilenameLabel->setText(QApplication::translate("MainWindow", "File is missing", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Open File", nullptr));
        Button_PlayPause->setText(QApplication::translate("MainWindow", "Play/Pause", nullptr));
        Button_NextFrame->setText(QApplication::translate("MainWindow", "next frame", nullptr));
        Button_PreviousFrame->setText(QApplication::translate("MainWindow", "previous", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        Lable_Pixmap->setText(QString());
        Lable_Pixmap2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
