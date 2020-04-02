#include "erreurauthentification.h"
#include "ui_erreurauthentification.h"

Erreurauthentification::Erreurauthentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erreurauthentification)
{
    ui->setupUi(this);
}

Erreurauthentification::~Erreurauthentification()
{
    delete ui;
}

void Erreurauthentification::on_pushButton_clicked()
{
    this->close();
}
