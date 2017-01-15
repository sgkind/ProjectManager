#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtSql>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>

class ContactInfo : public QWidget
{
    Q_OBJECT
public:
    explicit ContactInfo(QWidget *parent = 0);

private:
    QSqlQuery query;
    QSqlTableModel *model;
    QTableView *tableView;

    QLineEdit *nameLineEdit;
    QLineEdit *companyLineEdit;
    QPushButton *searchBtn;
    QHBoxLayout *searchLayout;
    QVBoxLayout *mainLayout;

    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QPushButton *submitAllBtn;

    void paint();

signals:

public slots:
    void search();
    void addContact();
    void deleteContact();
    void submitAll();
};

#endif // CONTACTINFO_H
