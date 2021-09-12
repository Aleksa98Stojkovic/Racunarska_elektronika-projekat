/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTabWidget *tabWidget;
    QWidget *main;
    QLineEdit *lineEdit;
    QLabel *label_21;
    QPushButton *stop_button;
    QPushButton *start_button;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QCustomPlot *customPlot;
    QWidget *settings;
    QComboBox *comboBox_1;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QComboBox *comboBox_4;
    QLabel *label_4;
    QComboBox *comboBox_5;
    QLabel *label_5;
    QComboBox *comboBox_11;
    QLabel *label_11;
    QComboBox *comboBox_12;
    QLabel *label_12;
    QComboBox *comboBox_13;
    QLabel *label_13;
    QComboBox *comboBox_14;
    QLabel *label_14;
    QComboBox *comboBox_15;
    QLabel *label_15;
    QComboBox *comboBox_16;
    QLabel *label_16;
    QComboBox *comboBox_17;
    QLabel *label_17;
    QComboBox *comboBox_18;
    QLabel *label_18;
    QComboBox *comboBox_19;
    QLabel *label_19;
    QComboBox *comboBox_20;
    QLabel *label_20;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1304, 624);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(100, 10, 711, 571));
        main = new QWidget();
        main->setObjectName(QStringLiteral("main"));
        lineEdit = new QLineEdit(main);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(570, 50, 71, 38));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        label_21 = new QLabel(main);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(550, 10, 131, 28));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_21->setFont(font1);
        stop_button = new QPushButton(main);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(360, 480, 85, 36));
        stop_button->setFont(font);
        start_button = new QPushButton(main);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(269, 480, 85, 36));
        start_button->setFont(font);
        label_6 = new QLabel(main);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(320, 10, 131, 28));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        label_6->setFont(font2);
        lineEdit_2 = new QLineEdit(main);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 50, 113, 38));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        customPlot = new QCustomPlot(main);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(59, 109, 581, 341));
        tabWidget->addTab(main, QString());
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        comboBox_1 = new QComboBox(settings);
        comboBox_1->setObjectName(QStringLiteral("comboBox_1"));
        comboBox_1->setGeometry(QRect(27, 70, 97, 38));
        label = new QLabel(settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 70, 71, 28));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        label->setFont(font4);
        comboBox_2 = new QComboBox(settings);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(27, 140, 97, 38));
        label_2 = new QLabel(settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 140, 64, 38));
        label_2->setFont(font4);
        comboBox_3 = new QComboBox(settings);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(27, 220, 97, 38));
        label_3 = new QLabel(settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 220, 64, 38));
        label_3->setFont(font4);
        comboBox_4 = new QComboBox(settings);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(27, 300, 97, 38));
        label_4 = new QLabel(settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 300, 64, 38));
        label_4->setFont(font4);
        comboBox_5 = new QComboBox(settings);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(27, 380, 97, 38));
        label_5 = new QLabel(settings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(130, 380, 64, 38));
        label_5->setFont(font4);
        comboBox_11 = new QComboBox(settings);
        comboBox_11->setObjectName(QStringLiteral("comboBox_11"));
        comboBox_11->setGeometry(QRect(247, 70, 97, 38));
        label_11 = new QLabel(settings);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(350, 70, 64, 38));
        label_11->setFont(font4);
        comboBox_12 = new QComboBox(settings);
        comboBox_12->setObjectName(QStringLiteral("comboBox_12"));
        comboBox_12->setGeometry(QRect(247, 140, 97, 38));
        label_12 = new QLabel(settings);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(350, 140, 64, 38));
        label_12->setFont(font4);
        comboBox_13 = new QComboBox(settings);
        comboBox_13->setObjectName(QStringLiteral("comboBox_13"));
        comboBox_13->setGeometry(QRect(247, 220, 97, 38));
        label_13 = new QLabel(settings);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(350, 220, 64, 38));
        label_13->setFont(font4);
        comboBox_14 = new QComboBox(settings);
        comboBox_14->setObjectName(QStringLiteral("comboBox_14"));
        comboBox_14->setGeometry(QRect(247, 300, 97, 38));
        label_14 = new QLabel(settings);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(350, 300, 64, 38));
        label_14->setFont(font4);
        comboBox_15 = new QComboBox(settings);
        comboBox_15->setObjectName(QStringLiteral("comboBox_15"));
        comboBox_15->setGeometry(QRect(247, 380, 97, 38));
        label_15 = new QLabel(settings);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(350, 380, 64, 38));
        label_15->setFont(font4);
        comboBox_16 = new QComboBox(settings);
        comboBox_16->setObjectName(QStringLiteral("comboBox_16"));
        comboBox_16->setGeometry(QRect(477, 70, 97, 38));
        label_16 = new QLabel(settings);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(580, 70, 64, 38));
        label_16->setFont(font4);
        comboBox_17 = new QComboBox(settings);
        comboBox_17->setObjectName(QStringLiteral("comboBox_17"));
        comboBox_17->setGeometry(QRect(477, 140, 97, 38));
        label_17 = new QLabel(settings);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(580, 140, 64, 38));
        label_17->setFont(font4);
        comboBox_18 = new QComboBox(settings);
        comboBox_18->setObjectName(QStringLiteral("comboBox_18"));
        comboBox_18->setGeometry(QRect(477, 220, 97, 38));
        label_18 = new QLabel(settings);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(580, 220, 64, 38));
        label_18->setFont(font4);
        comboBox_19 = new QComboBox(settings);
        comboBox_19->setObjectName(QStringLiteral("comboBox_19"));
        comboBox_19->setGeometry(QRect(477, 300, 97, 38));
        label_19 = new QLabel(settings);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(580, 300, 64, 38));
        label_19->setFont(font4);
        comboBox_20 = new QComboBox(settings);
        comboBox_20->setObjectName(QStringLiteral("comboBox_20"));
        comboBox_20->setGeometry(QRect(477, 380, 97, 38));
        label_20 = new QLabel(settings);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(580, 380, 64, 38));
        label_20->setFont(font4);
        tabWidget->addTab(settings, QString());

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_21->setText(QApplication::translate("Dialog", "Played Note", nullptr));
        stop_button->setText(QApplication::translate("Dialog", "Stop", nullptr));
        start_button->setText(QApplication::translate("Dialog", "Start", nullptr));
        label_6->setText(QApplication::translate("Dialog", "TV Command", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(main), QApplication::translate("Dialog", "Main", nullptr));
        label->setText(QApplication::translate("Dialog", "On/Off", nullptr));
        label_2->setText(QApplication::translate("Dialog", "V+", nullptr));
        label_3->setText(QApplication::translate("Dialog", "V-", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Ch+", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Ch-", nullptr));
        label_11->setText(QApplication::translate("Dialog", "Key 0", nullptr));
        label_12->setText(QApplication::translate("Dialog", "Key 1", nullptr));
        label_13->setText(QApplication::translate("Dialog", "Key 2", nullptr));
        label_14->setText(QApplication::translate("Dialog", "Key 3", nullptr));
        label_15->setText(QApplication::translate("Dialog", "Key 4", nullptr));
        label_16->setText(QApplication::translate("Dialog", "Key 5", nullptr));
        label_17->setText(QApplication::translate("Dialog", "Key 6", nullptr));
        label_18->setText(QApplication::translate("Dialog", "Key 7", nullptr));
        label_19->setText(QApplication::translate("Dialog", "Key 8", nullptr));
        label_20->setText(QApplication::translate("Dialog", "Key 9", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settings), QApplication::translate("Dialog", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
