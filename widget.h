#ifndef WIDGET_H
#define WIDGET_H

#include "projectinfo.h"
#include "fileinfo.h"
#include "contactinfo.h"

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

    QStackedWidget *stack;
    ProjectInfo *projectInfo;
    FileInfo *fileInfo;
    ContactInfo *contactInfo;
    //QLabel *label2;
    //QLabel *label3;

private:
    QSqlQuery query;

signals:

public slots:
};

#endif // WIDGET_H
