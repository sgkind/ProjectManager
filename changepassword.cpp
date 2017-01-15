#include "changepassword.h"

ChangePassword::ChangePassword(QWidget* parent) : QDialog(parent)
{
    setWindowTitle(tr("修改登录密码"));
    passwordLabel = new QLabel(tr("原密码："));
    newPasswordLabel1 = new QLabel(tr("新密码："));
    newPasswordLabel2 = new QLabel(tr("确认密码："));

    passwordLineEdit = new QLineEdit;
    newPasswordLineEdit1 = new QLineEdit;
    newPasswordLineEdit2 = new QLineEdit;

    passwordLineEdit->setEchoMode(QLineEdit::Password);
    newPasswordLineEdit1->setEchoMode(QLineEdit::Password);
    newPasswordLineEdit2->setEchoMode(QLineEdit::Password);

    save = new QPushButton(tr("修改"));

    gridLayout = new QGridLayout();
    gridLayout->addWidget(passwordLabel, 0, 0);
    gridLayout->addWidget(passwordLineEdit, 0, 1);
    gridLayout->addWidget(newPasswordLabel1, 1, 0);
    gridLayout->addWidget(newPasswordLineEdit1, 1, 1);
    gridLayout->addWidget(newPasswordLabel2, 2, 0);
    gridLayout->addWidget(newPasswordLineEdit2, 2, 1);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(save);

    connect(save, SIGNAL(clicked()), this, SLOT(Password()));
}

void ChangePassword::Password()
{
    User user;
    QString password = passwordLineEdit->text();
    QString newPassword1 = newPasswordLineEdit1->text();
    QString newPassword2 = newPasswordLineEdit2->text();
    if(password.isEmpty())
    {
        QMessageBox::information(this, tr("请输入旧密码"),tr("请先输入旧密码！"), QMessageBox::Ok);
        passwordLineEdit->setFocus();
    }
    else if (newPassword1.isEmpty())
    {
        QMessageBox::information(this, tr("请输入新密码"), tr("请输入新密码！"), QMessageBox::Ok);
        newPasswordLineEdit1->setFocus();
    }
    else if (newPassword2.isEmpty())
    {
        QMessageBox::information(this, tr("请确认新密码"), tr("请确认新密码！"), QMessageBox::Ok);
        newPasswordLineEdit2->setFocus();
    }
    else if (newPassword1 != newPassword2)
    {
        QMessageBox::information(this, tr("请确认新密码"), tr("新密码两次输入不相同！"), QMessageBox::Ok);
        newPasswordLineEdit2->setFocus();
    } else
    {
        bool success = user.update_password(QString("sunguanke") , password, newPassword1);
        if (success)
            close();
        else
            QMessageBox::information(this, tr("修改密码失败"), tr("修改密码失败！"), QMessageBox::Ok);
    }
}
