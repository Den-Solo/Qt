#include "classic.h"
#include "ui_classic.h"

Classic::Classic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Classic)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));


    for (int i = 0; i < 11; ++i){
        QString butName = "Button" + QString::number(i);
        connect(Classic::findChild<QPushButton *>(butName), SIGNAL(released()),
                this, SLOT(NumPressed()));
    }

    connect(ui->Button10, SIGNAL(released()),
            this, SLOT(NumPressed()));
    connect(ui->ButtonDiv, SIGNAL(released()),
            this, SLOT(MathButtonPressed()));
    connect(ui->ButtonMult, SIGNAL(released()),
            this, SLOT(MathButtonPressed()));
    connect(ui->ButtonAdd, SIGNAL(released()),
            this, SLOT(MathButtonPressed()));
    connect(ui->ButtonSub, SIGNAL(released()),
            this, SLOT(MathButtonPressed()));
    connect(ui->ButtonEq, SIGNAL(released()),
            this, SLOT(EqualButton()));
}

Classic::~Classic()
{
    delete ui;
}


void Classic::NumPressed(){
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();

    if (butVal == "."){
        if (displayVal == "0"){
            ui->Display->setText("0.");
            return;
        }
        else if (displayVal.contains('.')){
            return;
        }
    }

    if (displayVal == "0")
        ui->Display->setText(butVal);
    else
        ui->Display->setText(displayVal + butVal);

}



void Classic::MathButtonPressed(){

    QString displayVal = ui->Display->text();

    if (displayVal != "0"){
         EqualButton(true);
    }
    DisableTriggers();

    displayVal = ui->Display->text();
    if (calcVal == 0.0)
        calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    if (butVal == "/"){
        divTrigger = true;
    }
    else  if (butVal == "*"){
        multTrigger = true;
    }else  if (butVal == "+"){
        addTrigger = true;
    }else  if (butVal == "-"){
        subTrigger = true;
    }

    if (displayVal != "0")
        ui->DisplaySupport->setText(QString::number(calcVal, 'g',16) + ' ' + butVal);
    else {//change sign only
        displayVal = ui->DisplaySupport->text();
        if (displayVal.size()){
            displayVal.back() = butVal[0];
            ui->DisplaySupport->setText(displayVal);
        }
    }
    ui->Display->setText("0");
}

void Classic::EqualButton(bool intermediate)
{
    if (addTrigger || subTrigger || multTrigger || divTrigger){

        QString displayVal = ui->Display->text();
        double dblDisplayVal = displayVal.toDouble();

        if (addTrigger)
            calcVal += dblDisplayVal;
        else if (subTrigger)
            calcVal -= dblDisplayVal;
        else if (multTrigger)
            calcVal *= dblDisplayVal;
        else
            calcVal /= dblDisplayVal;

        ui->Display->setText(QString::number(calcVal, 'g', 16));
        if (!intermediate){
            ui->DisplaySupport->setText(ui->DisplaySupport->text() + ' ' + displayVal + " =");
        }
        DisableTriggers();
    }

}





void Classic::on_ButtonAC_released()
{
    DisableTriggers();

    calcVal = 0.0;
    ui->Display->setText("0");
    ui->DisplaySupport->setText("");
}

void Classic::on_pushButton_released()
{
    QString displayVal = ui->Display->text();
    if (displayVal.size() > 1){
        ui->Display->setText(displayVal.mid(0, displayVal.size() - 1));
    }else{
        ui->Display->setText("0");
    }
}


void Classic::DisableTriggers(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
}
