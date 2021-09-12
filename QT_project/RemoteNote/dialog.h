#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "pitchdetector.hpp"
#include <QString>
#include <QTimer>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void work();

private slots:

    void MakePlot();

    void on_comboBox_1_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_comboBox_12_currentTextChanged(const QString &arg1);

    void on_comboBox_13_currentTextChanged(const QString &arg1);

    void on_comboBox_14_currentTextChanged(const QString &arg1);

    void on_comboBox_15_currentTextChanged(const QString &arg1);

    void on_comboBox_16_currentTextChanged(const QString &arg1);

    void on_comboBox_17_currentTextChanged(const QString &arg1);

    void on_comboBox_18_currentTextChanged(const QString &arg1);

    void on_comboBox_19_currentTextChanged(const QString &arg1);

    void on_comboBox_20_currentTextChanged(const QString &arg1);

    void on_start_button_clicked();

    void on_stop_button_clicked();

    void on_pushButton_clicked();

    void on_comboBox_31_currentTextChanged(const QString &arg1);

    void on_comboBox_32_currentTextChanged(const QString &arg1);

    void on_comboBox_33_currentTextChanged(const QString &arg1);

    void on_comboBox_34_currentTextChanged(const QString &arg1);

    void on_comboBox_35_currentTextChanged(const QString &arg1);

    void on_comboBox_36_currentTextChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    Pitch_Detector *pd;
    std::tr1::unordered_map<std::string, std::string> settings_map;
    QTimer *timer;
    std::string filename;
    QString no_pitch;
    std::string cmd;
    std::string pitch;
    std::string ir_cmd;
    QVector<double> x;
    QVector<double> y;
    QVector<int> sett;
};

#endif // DIALOG_H
