#ifndef SDETAILINFO_H
#define SDETAILINFO_H

#include "utility.h"
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QGridLayout>
#include <QVBoxLayout>

class SDetailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit SDetailInfo(QWidget *parent = 0);

    void setContents(Stage &stage);
    void editEnabled();

    void save(QString &path);

private:
    QLabel *informationLabel;
    QTextEdit *informationTextEdit;

    QVBoxLayout *mainLayout;

signals:

public slots:
};

#endif // SDETAILINFO_H
