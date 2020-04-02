#ifndef ERREURAUTHENTIFICATION_H
#define ERREURAUTHENTIFICATION_H

#include <QDialog>
#include <QProcess>
#include <QMouseEvent>
#include <QMediaPlayer>

namespace Ui {
class Erreurauthentification;
}

class Erreurauthentification : public QDialog
{
    Q_OBJECT

public:
    explicit Erreurauthentification(QWidget *parent = nullptr);
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    ~Erreurauthentification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Erreurauthentification *ui;
    QProcess *m_process2 = new QProcess;
    QMediaPlayer *player = new QMediaPlayer;
    bool play = false;
};

#endif // ERREURAUTHENTIFICATION_H
