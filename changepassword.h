#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include "utility.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMessageBox>

class ChangePassword : public QDialog
{
    Q_OBJECT
public:
    ChangePassword(QWidget *parent = 0);

private:
    QLabel *passwordLabel;
    QLabel *newPasswordLabel1;
    QLabel *newPasswordLabel2;

    QLineEdit *passwordLineEdit;
    QLineEdit *newPasswordLineEdit1;
    QLineEdit *newPasswordLineEdit2;

    QPushButton *save;

    QGridLayout *gridLayout;
    QVBoxLayout *mainLayout;

public slots:
    void Password();
};

#endif // CHANGEPASSWORD_H
