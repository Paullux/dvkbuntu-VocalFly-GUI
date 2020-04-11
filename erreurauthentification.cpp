#include "erreurauthentification.h"
#include "ui_erreurauthentification.h"
#include <QThread>
#include <QDialog>

Erreurauthentification::Erreurauthentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erreurauthentification)
{
    ui->setupUi(this);
    m_process2->start("createWaveFromItem \"Echec de lauthentification les paramètres choisis ne seront pas pris en compte.\"");
    m_process2->waitForFinished(-1);
    m_process2->start("aplay " + env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav");
    play=true;
}

Erreurauthentification::~Erreurauthentification()
{
    delete ui;
}

void Erreurauthentification::on_pushButton_clicked()
{
    player->stop();
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}
