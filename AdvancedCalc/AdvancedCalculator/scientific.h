#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <QWidget>

namespace Ui {
class Scientific;
}

class Scientific : public QWidget
{
    Q_OBJECT

public:
    explicit Scientific(QWidget *parent = nullptr);
    ~Scientific();

private:
    Ui::Scientific *ui;
};

#endif // SCIENTIFIC_H
