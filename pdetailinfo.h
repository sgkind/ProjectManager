#ifndef PDETAILINFO_H
#define PDETAILINFO_H

#include "utility.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

class PDetailInfo : public QWidget
{
    Q_OBJECT
public:
    explicit PDetailInfo(QWidget *parent = 0);

    void setContents(QString &name, Project &project);
    void editEnabled();

    void save(QString &path);

private:
    QLabel *projectNameLabel;
    QLabel *projectCodeNameLabel;
    QLabel *OEMNameLabel;
    QLabel *HVACEngineerLabel;
    QLabel *electricianLabel;
    QLineEdit *projectNameLineEdit;
    QLineEdit *projectCodeNameLineEdit;
    QLineEdit *OEMNameLineEdit;
    QLineEdit *HVACEngineerLineEdit;
    QLineEdit *electricianLineEdit;
    QGridLayout *mainLayout;

signals:

public slots:
};

#endif // PDETAILINFO_H
