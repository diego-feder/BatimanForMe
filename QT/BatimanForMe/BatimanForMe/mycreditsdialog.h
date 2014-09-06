#ifndef MYCREDITSDIALOG_H
#define MYCREDITSDIALOG_H

#include <QDialog>

namespace Ui {
class MyCreditsDialog;
}

class MyCreditsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyCreditsDialog(QWidget *parent = 0);
    ~MyCreditsDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyCreditsDialog *ui;
};

#endif // MYCREDITSDIALOG_H
