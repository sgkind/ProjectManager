#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"
#include "utility.h"
#include "changepassword.h"

#include <QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Widget *widget;

    QMenu *manageMenu;
    QMenu *passwordMenu;

    QAction *fileManageAction;
    QAction *projectInfoAction;
    QAction *otherAction;
    QAction *quitAction;
    QAction *passwordAction;

private slots:
    void on_quitMenu_clicked();
    void createMenuBar();
    void change0();
    void change1();
    void change2();
    void change_password();
};

#endif // MAINWINDOW_H
