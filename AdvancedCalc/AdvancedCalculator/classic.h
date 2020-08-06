#ifndef CLASSIC_H
#define CLASSIC_H

#include <QWidget>

namespace Ui {
class Classic;
}

class Classic : public QWidget
{
    Q_OBJECT

public:
    explicit Classic(QWidget *parent = nullptr);
    ~Classic();


private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton(bool intermediate = false);
    void DisableTriggers();

    void on_ButtonAC_released();
    void on_pushButton_released();


private:
    Ui::Classic *ui;

    double calcVal = 0.0;
    bool divTrigger = false;
    bool multTrigger = false;
    bool addTrigger = false;
    bool subTrigger = false;
};

#endif // CLASSIC_H
