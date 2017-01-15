#include "sdetailinfo.h"

SDetailInfo::SDetailInfo(QWidget *parent) : QWidget(parent)
{
    informationLabel = new QLabel(tr("备注："));
    informationTextEdit = new QTextEdit;

    informationTextEdit->setEnabled(false);
    informationTextEdit->setStyleSheet("background-color:white; color:black");

    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(informationLabel);
    mainLayout->addWidget(informationTextEdit);
}

void SDetailInfo::setContents(Stage &stage)
{
    informationTextEdit->setText(stage.getNote());
}

void SDetailInfo::editEnabled()
{
    informationTextEdit->setEnabled(true);
}

void SDetailInfo::save(QString &path)
{
    Stage stage(path);
    stage.setNote(informationTextEdit->toPlainText());
    stage.update();

    informationTextEdit->setEnabled(false);
    informationTextEdit->setStyleSheet("background-color:white; color:black");
}
