#include "cadetailinfo.h"

CADetailInfo::CADetailInfo(QWidget *parent) : QWidget(parent)
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

void CADetailInfo::setContents(Category &category)
{
    informationTextEdit->setText(category.getNote());
}

void CADetailInfo::editEnabled()
{
    informationTextEdit->setEnabled(true);
}

void CADetailInfo::save(QString &path)
{
    Category category(path);
    category.setNote(informationTextEdit->toPlainText());
    category.update();

    informationTextEdit->setEnabled(false);
    informationTextEdit->setStyleSheet("background-color:white; color:black");
}
