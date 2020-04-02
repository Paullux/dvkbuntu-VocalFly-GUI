#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    player->stop();
    player->setVolume(50);
    if (!play) {
        m_process2->start("createWaveFromItem \"HandyOpenSource est une association loi 1901, à but non lucratif qui a été mise en place afin de supporter le développement du projet de la distribution DVKBuntu. Nous vivons une époque où l'informatique fait partie intégrante de notre vie personnelle et professionnelle. Aujourd'hui, force est de constater que tous ne sont pas égaux dans l'utilisation de l’outil informatique.\"");
        m_process2->waitForFinished(-1);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_clicked()
{
    player->stop();
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}
