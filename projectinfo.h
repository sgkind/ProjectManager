#ifndef PROJECTINFO_H
#define PROJECTINFO_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>

class ProjectInfo : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectInfo(QWidget *parent = 0);
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QPushButton *searchBtn;

    QTableWidget *projectTable;


signals:

public slots:
};

#endif // PROJECTINFO_H
