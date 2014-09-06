#ifndef NAMEINPUT_H
#define NAMEINPUT_H

#include <QDialog>

namespace Ui {
class NameInput;
}

class NameInput : public QDialog
{
    Q_OBJECT

public:
    explicit NameInput(QWidget *parent = 0);
    ~NameInput();

private:
    Ui::NameInput *ui;
};

#endif // NAMEINPUT_H
