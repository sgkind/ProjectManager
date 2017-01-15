#include "filedetailinfo.h"

FileDetailInfo::FileDetailInfo(QWidget *parent) : QWidget(parent)
{
    createTimeLabel = new QLabel(tr("创建时间："));
    createTimeEdit = new QDateTimeEdit;
    editTimeLabel = new QLabel(tr("修改时间："));
    editTimeEdit = new QDateTimeEdit;

    editLabel = new QLabel(tr("修改内容："));
    editTextEdit = new QTextEdit;

    createTimeEdit->setEnabled(false);
    editTimeEdit->setEnabled(false);
    editTextEdit->setEnabled(false);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(createTimeLabel, 0, 0);
    mainLayout->addWidget(createTimeEdit, 0, 1);
    mainLayout->addWidget(editTimeLabel, 1, 0);
    mainLayout->addWidget(editTimeEdit, 1, 1);
    mainLayout->addWidget(editLabel, 2, 0);
    mainLayout->addWidget(editTextEdit, 3, 0, 1, 2);
}

void FileDetailInfo::setContents(File &file)
{
    createTimeEdit->setDateTime(QDateTime::fromString(file.getCreate(), tr("yyyy-MM-dd hh:mm:ss")));
    editTimeEdit->setDateTime(QDateTime::fromString(file.getModify(), tr("yyyy-MM-dd hh:mm:ss")));
    editTextEdit->setText(file.getNote());
}

void FileDetailInfo::editEnabled()
{
    editTimeEdit->setEnabled(true);
    createTimeEdit->setEnabled(true);
    editTextEdit->setEnabled(true);
}

void FileDetailInfo::save(QString &path)
{
    File file(path);
    file.setNote(editTextEdit->toPlainText());
    file.setCreate(createTimeEdit->text());
    file.setModify(editTimeEdit->text());
    file.update();
}
