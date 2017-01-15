#ifndef CDETAILINFO_H
#define CDETAILINFO_H

#include "utility.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

class CDetailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit CDetailInfo(QWidget *parent = 0);
    void setContents(Component component);
    void editEnabled();

    void save(QString &path);

private:
    QLabel *pNumberLabel;
    QLabel *supplyLabel;
    QLabel *engineerLabel;

    QLineEdit *pNumberLineEdit;
    QLineEdit *supplyLineEdit;
    QLineEdit *engineerLineEdit;

    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // CDETAILINFO_H
