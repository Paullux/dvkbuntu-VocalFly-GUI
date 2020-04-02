#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    player->stop();
    player->setVolume(50);
    m_process2->start("createWaveFromItem \"VocalFly est un service de vocalisation de l'interface de la Distribution DVKBuntu. Le but de ce service est de permettre notamment aux personnes malvoyantes de pouvoir accéder à l'informatique.\"");
    m_process2->waitForFinished(-1);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
    if (!play) {
        player->play();
        play=true;
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    player->stop();
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}
