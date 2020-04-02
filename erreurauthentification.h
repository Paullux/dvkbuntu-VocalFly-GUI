#ifndef ERREURAUTHENTIFICATION_H
#define ERREURAUTHENTIFICATION_H

#include <QDialog>

namespace Ui {
class Erreurauthentification;
}

class Erreurauthentification : public QDialog
{
    Q_OBJECT

public:
    explicit Erreurauthentification(QWidget *parent = nullptr);
    ~Erreurauthentification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Erreurauthentification *ui;
};

#endif // ERREURAUTHENTIFICATION_H
