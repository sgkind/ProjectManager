#ifndef PROJECTINFO_H
#define PROJECTINFO_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QSqlRelationalTableModel>

class ProjectInfo : public QWidget
{
    Q_OBJECT
public:
    explicit ProjectInfo(QWidget *parent = 0);


private:
    QTableView *tableView;
    QLineEdit *nameLineEdit;
    QLineEdit *codeLineEdit;
    QLineEdit *componentLineEdit;
    QPushButton *searchBtn;

    QSqlRelationalTableModel *model;



signals:

public slots:
    void search();
};

#endif // PROJECTINFO_H
