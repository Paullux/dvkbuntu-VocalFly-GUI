#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFermer_triggered()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_action_propos_de_VocalFly_triggered()
{
    objmain1=new Dialog;
    objmain1->show();
}

void MainWindow::on_action_propos_de_DVKbuntu_triggered()
{
    objmain2=new Dialog2;
    objmain2->show();
}

void MainWindow::on_action_propos_d_HandyOpenSource_triggered()
{
    objmain3=new Dialog3;
    objmain3->show();
}

void MainWindow::on_Google_toggled(bool checked)
{
    Google=checked;
}

void MainWindow::on_EspeakNG_toggled(bool checked)
{
    EspeakNG=checked;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    VocalFlyActivate=checked;
}

void MainWindow::on_pushButton_clicked()
{
    if (Google) {
        if (VocalFlyActivate) {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/local/bin/google_speech-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=true/' /usr/bin/createWaveFromItem\"");
        } else {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/local/bin/google_speech-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=false/' /usr/bin/createWaveFromItem\"");
        }
    } else {
        if (VocalFlyActivate) {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/espeak-ng-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=true/' /usr/bin/createWaveFromItem\"");
        } else {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/espeak-ng-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=false/' /usr/bin/createWaveFromItem\"");
        }
    }

    m_process->waitForFinished(-1);

    if (m_process->exitCode()==126 || m_process->exitCode()==127) {
        objmain4=new Erreurauthentification;
        objmain4->show();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
