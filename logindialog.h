#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "utility.h"
#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_loginBtn_clicked();

    void on_quitBtn_clicked();

private:
    Ui::LoginDialog *ui;
    User *user;
};

#endif // LOGINDIALOG_H
