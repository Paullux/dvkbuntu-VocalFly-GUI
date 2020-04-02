#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>
#include <QMouseEvent>
#include <QMediaPlayer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QProcess *m_process2 = new QProcess;
    QMediaPlayer *player = new QMediaPlayer;
    bool play = false;
};

#endif // DIALOG_H
