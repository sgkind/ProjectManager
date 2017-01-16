#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileInfo = new FileInfo;
    projectInfo = new ProjectInfo;
    contactInfo = new ContactInfo;

    stack = new QStackedWidget(this);
    stack->addWidget(fileInfo);
    stack->addWidget(projectInfo);
    stack->addWidget(contactInfo);

    stack->setMinimumSize(900, 500);

    createMenuBar();
    setCentralWidget(stack);
    setWindowTitle(tr("项目文档管理系系统"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenuBar()
{
    fileManageAction = new QAction(tr("文件管理"), this);
    fileManageAction->setShortcut(tr("Ctrl+F"));
    projectInfoAction = new QAction(tr("项目信息"), this);
    projectInfoAction->setShortcut(tr("Ctrl+P"));
    otherAction = new QAction(tr("联系人信息"), this);
    otherAction->setShortcut(tr("Ctrl+C"));
    quitAction = new QAction(tr("退出"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    passwordAction = new QAction(tr("修改密码"), this);
    passwordAction->setShortcut(tr("Ctrl+W"));

    manageMenu = menuBar()->addMenu(tr("项目管理"));
    manageMenu->addAction(fileManageAction);
    manageMenu->addAction(projectInfoAction);
    manageMenu->addAction(otherAction);
    manageMenu->addSeparator();
    manageMenu->addAction(quitAction);
    passwordMenu = menuBar()->addMenu(tr("修改密码"));
    passwordMenu->addAction(passwordAction);

    connect(fileManageAction, SIGNAL(triggered()), this, SLOT(change0()));
    connect(projectInfoAction, SIGNAL(triggered()), this, SLOT(change1()));
    connect(otherAction, SIGNAL(triggered()), this, SLOT(change2()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(on_quitMenu_clicked()));
    connect(passwordAction, SIGNAL(triggered()), this, SLOT(change_password()));
}

void MainWindow::on_quitMenu_clicked()
{
    this->close();
}

void MainWindow::change0()
{
    stack->setCurrentIndex(0);
}

void MainWindow::change1()
{
    stack->setCurrentIndex(1);
}

void MainWindow::change2()
{
    stack->setCurrentIndex(2);
}

void MainWindow::change_password()
{
    User user;
    ChangePassword *changePassword = new ChangePassword;
    changePassword->show();
}
