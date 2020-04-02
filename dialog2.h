#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QProcess>
#include <QMouseEvent>
#include <QMediaPlayer>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    ~Dialog2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog2 *ui;
    QProcess *m_process2 = new QProcess;
    QMediaPlayer *player = new QMediaPlayer;
    bool play = false;
};

#endif // DIALOG2_H
