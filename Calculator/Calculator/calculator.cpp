#include "calculator.h"
#include "ui_calculator.h"


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    ui->Display->setText(QString::number(calcVal));

    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()),
                this, SLOT(NumPressed()));

    }

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
    connect(ui->ButtonChangeSign, SIGNAL(released()),
            this, SLOT(ChangeNumberSign()));
}

Calculator::~Calculator()
{
    delete ui;
}



void Calculator::NumPressed(){
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if (displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0){
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}



void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    if (QString::compare(butVal, "/", Qt::CaseSensitive) == 0){
        divTrigger = true;
    }
    else  if (QString::compare(butVal, "*", Qt::CaseSensitive) == 0){
        multTrigger = true;
    }else  if (QString::compare(butVal, "+", Qt::CaseSensitive) == 0){
        addTrigger = true;
    }else  if (QString::compare(butVal, "-", Qt::CaseSensitive) == 0){
        subTrigger = true;
    }
    ui->Display->setText("");
}

void Calculator::EqualButton(){
    double solution = 0.0;
    double dblDisplayVal = ui->Display->text().toDouble();
    if (addTrigger || subTrigger || multTrigger || divTrigger){
        if (addTrigger)
            solution = calcVal + dblDisplayVal;
        else if (subTrigger)
            solution = calcVal - dblDisplayVal;
        else if (multTrigger)
            solution = calcVal * dblDisplayVal;
        else
            solution = calcVal / dblDisplayVal;
    }
    ui->Display->setText(QString::number(solution));
}

void Calculator::ChangeNumberSign(){
    QString displayVal = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if (reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}





