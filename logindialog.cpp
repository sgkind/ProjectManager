#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    setWindowTitle(tr("登录"));
    ui->userNameLineEdit->setFocus();
    ui->loginBtn->setDefault(true);
    user = new User();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->pwdLineEdit->text().isEmpty())
    {
        QMessageBox::information(this, tr("请输入密码"), tr("请先输入密码再登录!"), QMessageBox::Ok);
        ui->pwdLineEdit->setFocus();
    }
    else
    {
        if(user->user_query(ui->userNameLineEdit->text(), ui->pwdLineEdit->text())){
            QDialog::accept();
        }else {
            QMessageBox::warning(this, tr("密码错误"), tr("请先输入正确的密码再登录"), QMessageBox::Ok);
            ui->pwdLineEdit->clear();
            ui->pwdLineEdit->setFocus();
        }
    }
}



void LoginDialog::on_quitBtn_clicked()
{
    QDialog::reject();
}
