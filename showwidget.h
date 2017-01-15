#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QTextEdit>
#include <QSplitter>
#include <QListWidget>

class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = 0);

    QSplitter *splitterMain;

signals:

public slots:
};

#endif // SHOWWIDGET_H
