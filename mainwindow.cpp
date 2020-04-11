#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QMouseEvent>
#include <QAction>
#include <QEvent>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    player->stop();
    ui->setupUi(this);
    ui->centralWidget->installEventFilter(this);
    ui->Google->installEventFilter(this);
    ui->EspeakNG->installEventFilter(this);
    ui->pico2wave->installEventFilter(this);
    ui->checkBox->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);
    ui->action_propos_de_VocalFly->installEventFilter(this);
    ui->action_propos_de_DVKbuntu->installEventFilter(this);
    ui->action_propos_d_HandyOpenSource->installEventFilter(this);
    ui->TestGoogle->installEventFilter(this);
    ui->TestSpeak->installEventFilter(this);
    ui->TestPico->installEventFilter(this);
    if (!play) {
        m_process2->start("createWaveFromItem \"Interface de Gestion de VocalFLy\"");
        m_process2->waitForFinished(-1);
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
    /*player->stop();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() != QEvent::WindowDeactivate) {
        if (watched == ui->TestGoogle && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Test voix Google.\"");
        } else if (watched == ui->TestSpeak && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Test voix Espeak-NG.\"");
        } else if (watched == ui->TestPico && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Test voix Pico2wave.\"");
        } else if (watched == ui->Google && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Voix Google.\"");
        } else if (watched == ui->EspeakNG && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Voix Espeak-ng.\"");
        } else if (watched == ui->pico2wave && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Voix Pico2wave.\"");
        } else if (watched == ui->checkBox && event->type() == QEvent::HoverEnter) {
            if (VocalFlyActivate) {
                play=false;
                m_process2->start("createWaveFromItem \"VocalFly sera Activé après validation.\"");
            } else {
                play=false;
                m_process2->start("createWaveFromItem \"VocalFly sera Désactivé après validation.\"");
            }
        } else if (watched == ui->pushButton && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Valider les changements.\"");
        } else if (watched == ui->pushButton_2 && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Quitter sans valider les changements.\"");
        } else if (watched == ui->pushButton_3 && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"Quitter l'application.\"");
        } else if (watched == ui->action_propos_de_VocalFly && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"À propos de VocalFly.\"");
        } else if (watched == ui->action_propos_de_DVKbuntu && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"À propos de DVKbuntu.\"");
        } else if (watched == ui->action_propos_d_HandyOpenSource && event->type() == QEvent::HoverEnter) {
            play=false;
            m_process2->start("createWaveFromItem \"À propos de Handy OpenSource.\"");
        /*} else if (watched == ui->centralWidget && event->QEvent::HoverEnter) {
            m_process2->start("createWaveFromItem \"Interface de Gestion de VocalFLy\"");*/
        } else if ((watched == ui->TestGoogle || watched == ui->TestSpeak || watched == ui->TestPico || watched == ui->Google || watched == ui->EspeakNG || watched == ui->checkBox || watched == ui->pushButton || watched == ui->pushButton_2 || watched == ui->pushButton_3 || watched == ui->action_propos_de_VocalFly || watched == ui->action_propos_de_DVKbuntu || watched == ui->action_propos_d_HandyOpenSource || watched == ui->centralWidget) && event->type() == QEvent::HoverLeave) {
            play=false;
            player->stop();
            m_process2->start("createWaveFromItem \"Stop !\"");
        }
        m_process2->waitForFinished(-1);
        if (!play) {
            player->setVolume(50);
            player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
            player->play();
            play=true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
void MainWindow::on_actionFermer_triggered()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}

void MainWindow::on_action_propos_de_VocalFly_triggered()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    objmain1=new Dialog;
    objmain1->show();
}

void MainWindow::on_action_propos_de_DVKbuntu_triggered()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    objmain2=new Dialog2;
    objmain2->show();
}

void MainWindow::on_action_propos_d_HandyOpenSource_triggered()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    objmain3=new Dialog3;
    objmain3->show();
}

void MainWindow::on_Google_toggled(bool checked)
{
    Google=checked;
    play=false;
    m_process2->start("createWaveFromItem \"Voix Google Sélectionnée\"");
    m_process2->waitForFinished(-1);
    if (!play) {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
}

void MainWindow::on_EspeakNG_toggled(bool checked)
{
    EspeakNG=checked;
    play=false;
    m_process2->start("createWaveFromItem \"Voix Espeak-NG Sélectionnée\"");
    m_process2->waitForFinished(-1);
    if (!play) {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
}

void MainWindow::on_pico2wave_toggled(bool checked)
{
    pico2wave=checked;
    play=false;
    m_process2->start("createWaveFromItem \"Voix pico2wave Sélectionnée\"");
    m_process2->waitForFinished(-1);
    if (!play) {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    VocalFlyActivate=checked;
    if (VocalFlyActivate) {
        play=false;
        m_process2->start("createWaveFromItem \"VocalFly sera Activé après validation.\"");
    } else {
        play=false;
        m_process2->start("createWaveFromItem \"VocalFly sera Désactivé après validation.\"");
    }
    m_process2->waitForFinished(-1);
    if (!play) {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
        play=true;
    }
}

void MainWindow::on_pushButton_clicked()
{
    player->stop();
    m_process2->start("createWaveFromItem \"Entrez votre mot de passe administrateur.\"");
    m_process2->waitForFinished(-1);
    m_process2->start("aplay " + env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav");
    m_process2->waitForFinished(-1);
    play=true;

    if (player->state() != QMediaPlayer::PlayingState) { player->play(); }
    if (Google) {
        if (VocalFlyActivate) {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/local/bin/google_speech-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=true/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Activé et Voix Google.\"");
        } else {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/local/bin/google_speech-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=false/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Désactivé et Voix Google.\"");
        }
    } else if (EspeakNG) {
        if (VocalFlyActivate) {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/espeak-ng-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=true/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Activé et Voix Espeak-ng.\"");
        } else {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/espeak-ng-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=false/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Désactivé et Voix Espeak-ng.\"");
        }
    } else {
        if (VocalFlyActivate) {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/pico2wave-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=true/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Activé et Voix Pico.\"");
        } else {
            m_process->start("pkexec sh -c \"update-alternatives --set tts '/usr/bin/pico2wave-multilanguage' && sed -i 's/VOCALFLY=.*$/VOCALFLY=false/' /usr/bin/createWaveFromItem\"");
            m_process2->start("createWaveFromItem \"VocalFly Désactivé et Voix Pico.\"");
        }
    }

    m_process->waitForFinished(-1);
    m_process2->waitForFinished(-1);


    if (m_process->exitCode()==126 || m_process->exitCode()==127) {
        //m_process2->start("createWaveFromItem \"\"");
        //m_process2->waitForFinished(-1);
        MainWindow::destroy();
        objmain4=new Erreurauthentification;
        objmain4->show();
    } else {
        player->setVolume(50);
        player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/sonEnCours.wav"));
        player->play();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    m_process2->start("createWaveFromItem \"\"");
    m_process2->waitForFinished(-1);
    this->close();
}

void MainWindow::on_TestGoogle_clicked()
{
    m_process2->start("/usr/local/bin/google_speech-multilanguage \"Cette voix est issue de Google. La voix est plutôt jolie, mais elle nécessite internet pour fonctionner.\" \"fr-fr\" \"$HOME/.local/share/dvkbuntu/testvoix.wav\"");
    m_process2->waitForFinished(-1);
    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/testvoix.wav"));
    player->play();
}

void MainWindow::on_TestSpeak_clicked()
{
    m_process2->start("/usr/bin/espeak-ng-multilanguage \"Cette voix est 100% libre, elle est aussi entièrement locale (elle ne nécessite pas internet) mais en revanche elle est très robotique !\" \"fr-fr\" \"$HOME/.local/share/dvkbuntu/testvoix.wav\"");
    m_process2->waitForFinished(-1);
    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/testvoix.wav"));
    player->play();
}

void MainWindow::on_TestPico_clicked()
{
    m_process2->start("/usr/bin/pico2wave-multilanguage \"Cette voix est 100% libre, elle est aussi entièrement locale (elle ne nécessite pas internet) mais et elle est mieux que Espeak-NG !\" \"fr-fr\" \"$HOME/.local/share/dvkbuntu/testvoix.wav\"");
    m_process2->waitForFinished(-1);
    player->setVolume(50);
    player->setMedia(QUrl::fromLocalFile(env.value("HOME") + "/.local/share/dvkbuntu/testvoix.wav"));
    player->play();
}
