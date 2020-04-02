#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include <QProcess>
#include <QMouseEvent>
#include <QMediaPlayer>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    ~Dialog3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog3 *ui;
    QProcess *m_process2 = new QProcess;
    QMediaPlayer *player = new QMediaPlayer;
    bool play = false;
};

#endif // DIALOG3_H
