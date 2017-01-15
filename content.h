#ifndef CONTENT_H
#define CONTENT_H

#include <QStackedWidget>

class Content : public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *parent=0);
    QStackedWidget *stack;
};

#endif // CONTENT_H
