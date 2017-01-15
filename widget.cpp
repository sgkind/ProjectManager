#include "widget.h"

#include "treemodel.h"
#include <QDebug>
#include <QFile>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    fileInfo = new FileInfo;
    projectInfo = new ProjectInfo;
    contactInfo = new ContactInfo;


    stack = new QStackedWidget(this);
    //stack->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    stack->addWidget(fileInfo);
    stack->addWidget(projectInfo);
    stack->addWidget(contactInfo);
}


