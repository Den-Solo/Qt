#include "scientific.h"
#include "ui_scientific.h"

Scientific::Scientific(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scientific)
{
    ui->setupUi(this);
}

Scientific::~Scientific()
{
    delete ui;
}
