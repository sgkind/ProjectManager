#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "utility.h"
#include "changepassword.h"
#include "projectinfo.h"
#include "fileinfo.h"
#include "contactinfo.h"

#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Widget *widget;

    QMenu *manageMenu;
    QMenu *passwordMenu;

    QAction *fileManageAction;
    QAction *projectInfoAction;
    QAction *otherAction;
    QAction *quitAction;
    QAction *passwordAction;

private:
    QStackedWidget *stack;
    ProjectInfo *projectInfo;
    FileInfo *fileInfo;
    ContactInfo *contactInfo;

private slots:
    void on_quitMenu_clicked();
    void createMenuBar();
    void change0();
    void change1();
    void change2();
    void change_password();
};

#endif // MAINWINDOW_H
