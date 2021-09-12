#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pd = new Pitch_Detector(1024, 1024);
    std::vector<std::string> notes;
    notes = pd->get_notes();

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_1->addItem(str);
    }
    ui->comboBox_1->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_2->addItem(str);
    }
    ui->comboBox_2->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_3->addItem(str);
    }
    ui->comboBox_3->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_4->addItem(str);
    }
    ui->comboBox_4->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_5->addItem(str);
    }
    ui->comboBox_5->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_11->addItem(str);
    }
    ui->comboBox_11->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_12->addItem(str);
    }
    ui->comboBox_12->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_13->addItem(str);
    }
    ui->comboBox_13->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_14->addItem(str);
    }
    ui->comboBox_14->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_15->addItem(str);
    }
    ui->comboBox_15->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_16->addItem(str);
    }
    ui->comboBox_16->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_17->addItem(str);
    }
    ui->comboBox_17->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_18->addItem(str);
    }
    ui->comboBox_18->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_19->addItem(str);
    }
    ui->comboBox_19->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_20->addItem(str);
    }
    ui->comboBox_20->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_31->addItem(str);
    }
    ui->comboBox_31->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_32->addItem(str);
    }
    ui->comboBox_32->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_33->addItem(str);
    }
    ui->comboBox_33->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_34->addItem(str);
    }
    ui->comboBox_34->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_35->addItem(str);
    }
    ui->comboBox_35->addItem(QString::fromUtf8("None"));

    for(auto it = notes.begin(); it != notes.end(); it++)
    {
        QString str = QString::fromUtf8((*it).c_str());
        ui->comboBox_36->addItem(str);
    }
    ui->comboBox_36->addItem(QString::fromUtf8("None"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(work()));

    filename = "audio.wav";
    cmd = "arecord -D plughw:Device,0 -d 1 -f cd " +  filename;
    no_pitch = "Incorrect note play";
    ir_cmd = "irsend SEND_ONCE VoxTV ";

    Dialog::MakePlot();

    for(int i = 0; i < 51; i++)
    {
        x.push_back(i);
        y.push_back(65.41);
    }



    QFile file("settings.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Not able to open a file!\n";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        QString t1 = stream.readLine();
        std::string t2 = t1.toStdString();
        sett.push_back(stoi(t2));
    }

    file.close();

    ui->comboBox_1->setCurrentIndex(sett[0]);
    ui->comboBox_2->setCurrentIndex(sett[1]);
    ui->comboBox_3->setCurrentIndex(sett[2]);
    ui->comboBox_4->setCurrentIndex(sett[3]);
    ui->comboBox_5->setCurrentIndex(sett[4]);
    ui->comboBox_11->setCurrentIndex(sett[5]);
    ui->comboBox_12->setCurrentIndex(sett[6]);
    ui->comboBox_13->setCurrentIndex(sett[7]);
    ui->comboBox_14->setCurrentIndex(sett[8]);
    ui->comboBox_15->setCurrentIndex(sett[9]);
    ui->comboBox_16->setCurrentIndex(sett[10]);
    ui->comboBox_17->setCurrentIndex(sett[11]);
    ui->comboBox_18->setCurrentIndex(sett[12]);
    ui->comboBox_19->setCurrentIndex(sett[13]);
    ui->comboBox_20->setCurrentIndex(sett[14]);
    ui->comboBox_31->setCurrentIndex(sett[15]);
    ui->comboBox_32->setCurrentIndex(sett[16]);
    ui->comboBox_33->setCurrentIndex(sett[17]);
    ui->comboBox_34->setCurrentIndex(sett[18]);
    ui->comboBox_35->setCurrentIndex(sett[19]);
    ui->comboBox_36->setCurrentIndex(sett[20]);

    settings_map.insert(std::make_pair("KEY_POWER", ui->comboBox_1->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_V_PLUS", ui->comboBox_2->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_V_MINUS", ui->comboBox_3->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_Ch+", ui->comboBox_4->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_Ch-", ui->comboBox_5->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_0", ui->comboBox_11->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_1", ui->comboBox_12->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_1", ui->comboBox_13->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_2", ui->comboBox_14->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_3", ui->comboBox_15->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_4", ui->comboBox_16->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_5", ui->comboBox_17->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_6", ui->comboBox_18->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_7", ui->comboBox_19->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_8", ui->comboBox_20->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_9", ui->comboBox_31->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_UP", ui->comboBox_32->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_DOWN", ui->comboBox_33->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_LEFT", ui->comboBox_34->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_RIGHT", ui->comboBox_35->currentText().toStdString()));
    settings_map.insert(std::make_pair("KEY_MENU", ui->comboBox_36->currentText().toStdString()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::work()
{

    bool in = false;
    system(cmd.c_str());
    pd->load(filename);
    pitch = pd->note_estim();

    std::string full_ir_cmd = ir_cmd;
    std::string tv_cmd = "";

    // Pretrazujem mapu da vidim da li je nota medju dozvoljenim
    for(const auto& [k, v] : settings_map)
    {
        // qDebug() << QString::fromUtf8(k.c_str()) << " " << QString::fromUtf8(v.c_str()) << "\n";

        if(v == pitch)
        {
            in = true;
            tv_cmd = k;
        }
    }

    full_ir_cmd += tv_cmd;

    if(in)
    {
        ui->lineEdit->setText(QString::fromUtf8(pitch.c_str()));
        ui->lineEdit->setStyleSheet("QLineEdit {color: blue}");
        system(full_ir_cmd.c_str());
        ui->lineEdit_2->setText(QString::fromUtf8(tv_cmd.c_str()));
    }
    else
    {
        ui->lineEdit->setText(QString::fromUtf8(pitch.c_str()));
        ui->lineEdit->setStyleSheet("QLineEdit {color: red}");
    }

    y.erase(y.begin());
    y.push_back(pd->find_note(pitch));


    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
    ui->customPlot->update();

}

void Dialog::MakePlot()
{
    ui->customPlot->addGraph();
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->xAxis->setLabelColor(QColor(200, 200, 200));
    ui->customPlot->yAxis->setLabel("Frequency");
    ui->customPlot->yAxis->setLabelColor(QColor(200, 200, 200));
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 50);
    ui->customPlot->yAxis->setRange(65.41, 2093.0);
    ui->customPlot->replot();
    ui->customPlot->graph(0)->setBrush(QColor(10, 100, 50, 70));
    ui->customPlot->replot();
    ui->customPlot->graph(0)->setPen(QColor(200, 200, 200, 250));


    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);


}

void Dialog::on_comboBox_1_currentTextChanged(const QString &arg1)
{

    settings_map["KEY_POWER"] = arg1.toStdString();
}

void Dialog::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_V_PLUS"] = arg1.toStdString();
}

void Dialog::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_V_MINUS"] = arg1.toStdString();
}

void Dialog::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_Ch+"] = arg1.toStdString();
}

void Dialog::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_Ch-"] = arg1.toStdString();
}

void Dialog::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_0"] = arg1.toStdString();
}

void Dialog::on_comboBox_12_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_1"] = arg1.toStdString();
}

void Dialog::on_comboBox_13_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_2"] = arg1.toStdString();
}

void Dialog::on_comboBox_14_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_3"] = arg1.toStdString();
}

void Dialog::on_comboBox_15_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_4"] = arg1.toStdString();
}

void Dialog::on_comboBox_16_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_5"] = arg1.toStdString();
}

void Dialog::on_comboBox_17_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_6"] = arg1.toStdString();
}

void Dialog::on_comboBox_18_currentTextChanged(const QString &arg1)

{
    settings_map["KEY_7"] = arg1.toStdString();
}
void Dialog::on_comboBox_19_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_8"] = arg1.toStdString();
}

void Dialog::on_comboBox_20_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_9"] = arg1.toStdString();
}

void Dialog::on_comboBox_31_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_UP"] = arg1.toStdString();
}

void Dialog::on_comboBox_32_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_DOWN"] = arg1.toStdString();
}

void Dialog::on_comboBox_33_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_LEFT"] = arg1.toStdString();
}

void Dialog::on_comboBox_34_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_RIGHT"] = arg1.toStdString();
}

void Dialog::on_comboBox_35_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_MENU"] = arg1.toStdString();
}

void Dialog::on_comboBox_36_currentTextChanged(const QString &arg1)
{
    settings_map["KEY_OK"] = arg1.toStdString();
}

void Dialog::on_start_button_clicked()
{
    timer->start(1250); // 1.25 sekundi
}

void Dialog::on_stop_button_clicked()
{
    timer->stop();
}

void Dialog::on_pushButton_clicked()
{
    sett[0] = ui->comboBox_1->currentIndex();
    sett[1] = ui->comboBox_2->currentIndex();
    sett[2] = ui->comboBox_3->currentIndex();
    sett[3] = ui->comboBox_4->currentIndex();
    sett[4] = ui->comboBox_5->currentIndex();
    sett[5] = ui->comboBox_11->currentIndex();
    sett[6] = ui->comboBox_12->currentIndex();
    sett[7] = ui->comboBox_13->currentIndex();
    sett[8] = ui->comboBox_14->currentIndex();
    sett[9] = ui->comboBox_15->currentIndex();
    sett[10] = ui->comboBox_16->currentIndex();
    sett[11] = ui->comboBox_17->currentIndex();
    sett[12] = ui->comboBox_18->currentIndex();
    sett[13] = ui->comboBox_19->currentIndex();
    sett[14] = ui->comboBox_20->currentIndex();
    sett[15] = ui->comboBox_31->currentIndex();
    sett[16] = ui->comboBox_32->currentIndex();
    sett[17] = ui->comboBox_33->currentIndex();
    sett[18] = ui->comboBox_34->currentIndex();
    sett[19] = ui->comboBox_35->currentIndex();
    sett[20] = ui->comboBox_36->currentIndex();

    QFile file("settings.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Not able to open a file!\n";
        qCritical() << file.errorString();
    }

    QTextStream stream(&file);

    for(int i = 0; i < (int)sett.size(); i++)
    {
        stream << QString::number(sett[i]) << "\n";
    }

    file.close();
}

