#include "erreurauthentification.h"
#include "ui_erreurauthentification.h"

Erreurauthentification::Erreurauthentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erreurauthentification)
{
    ui->setupUi(this);
    player->setVolume(50);
    m_process2->start("createWaveFromItem \"Echec de lauthentification les paramètres choisis ne seront pas pris en compte.\"");
    m_process2->waitForFinished(-1);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
    if (!play) {
        player->play();
        play=true;
    }
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
