#ifndef FILEDETAILINFO_H
#define FILEDETAILINFO_H

#include "utility.h"
#include <QWidget>
#include <QLabel>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QGridLayout>

class FileDetailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit FileDetailInfo(QWidget *parent = 0);

    void setContents(File &file);
    void editEnabled();

    void save(QString &path);

private:
    QLabel *createTimeLabel;
    QLabel *editTimeLabel;
    QLabel *editLabel;

    QDateTimeEdit *createTimeEdit;
    QDateTimeEdit *editTimeEdit;
    QTextEdit *editTextEdit;

    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // FILEDETAILINFO_H
