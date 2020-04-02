#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    player->stop();
    player->setVolume(50);
    m_process2->start("createWaveFromItem \"DVKBuntu est une distribution GNU/Linux qui se veut accessible au plus grand nombre. Notamment aux personnes en situation de handicap divers. Et ceci grâce à des outils comme cette vocalisation de l'interface utilisateur ou l'utilisation d'un assistant vocal.\"");
    m_process2->waitForFinished(-1);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
    if (!play) {
        player->play();
        play=true;
    }
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    player->stop();
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}
