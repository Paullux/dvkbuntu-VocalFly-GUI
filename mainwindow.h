#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "dialog2.h"
#include "dialog3.h"
#include "erreurauthentification.h"
#include <QProcess>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QAction>
#include <QThread>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Dialog *objmain1;
    Dialog2 *objmain2;
    Dialog3 *objmain3;
    Erreurauthentification *objmain4;
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    ~MainWindow();

private slots:
    void on_actionFermer_triggered();

    void on_pushButton_2_clicked();

    void on_action_propos_de_VocalFly_triggered();

    void on_action_propos_de_DVKbuntu_triggered();

    void on_action_propos_d_HandyOpenSource_triggered();

    void on_Google_toggled(bool checked);

    void on_EspeakNG_toggled(bool checked);

    void on_pico2wave_toggled(bool checked);

    void on_checkBox_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    virtual bool eventFilter(QObject* watched, QEvent* event);

    void on_TestGoogle_clicked();

    void on_TestSpeak_clicked();

    void on_TestPico_clicked();

private:
    Ui::MainWindow *ui;
    bool Google = true;
    bool EspeakNG = false;
    bool pico2wave = false;
    bool VocalFlyActivate = true;
    QProcess *m_process = new QProcess;
    QProcess *m_process2 = new QProcess;
    QMediaPlayer *player = new QMediaPlayer;
    bool play = false;
};

#endif // MAINWINDOW_H
