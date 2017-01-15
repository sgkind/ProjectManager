#ifndef CADETAILINFO_H
#define CADETAILINFO_H

#include "utility.h"
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

class CADetailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit CADetailInfo(QWidget *parent = 0);

    void setContents(Category &category);
    void editEnabled();

    void save(QString &path);

private:
    QLabel *informationLabel;
    QTextEdit *informationTextEdit;
    QVBoxLayout *mainLayout;

signals:

public slots:
};

#endif // CADETAILINFO_H
