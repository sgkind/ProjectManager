#include "cdetailinfo.h"

CDetailInfo::CDetailInfo(QWidget *parent) : QWidget(parent)
{
    pNumberLabel = new QLabel(tr("件号:"));
    pNumberLineEdit = new QLineEdit;
    supplyLabel = new QLabel(tr("供应商:"));
    supplyLineEdit = new QLineEdit;
    engineerLabel = new QLabel(tr("工程师:"));
    engineerLineEdit = new QLineEdit;

    pNumberLineEdit->setEnabled(false);
    pNumberLineEdit->setStyleSheet("background-color:white; color:black");
    supplyLineEdit->setEnabled(false);
    supplyLineEdit->setStyleSheet("background-color:white; color:black");
    engineerLineEdit->setEnabled(false);
    engineerLineEdit->setStyleSheet("background-color:white; color:black");

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(pNumberLabel, 0, 0);
    mainLayout->addWidget(pNumberLineEdit, 0, 1);
    mainLayout->addWidget(supplyLabel, 1, 0);
    mainLayout->addWidget(supplyLineEdit, 1, 1);
    mainLayout->addWidget(engineerLabel, 2, 0);
    mainLayout->addWidget(engineerLineEdit, 2, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

void CDetailInfo::setContents(Component component)
{
    pNumberLineEdit->setText(component.getPnumber());
    supplyLineEdit->setText(component.getSupplier());
    engineerLineEdit->setText(component.getEngineer());
}

void CDetailInfo::editEnabled()
{
    pNumberLineEdit->setEnabled(true);
    supplyLineEdit->setEnabled(true);
    engineerLineEdit->setEnabled(true);
}

void CDetailInfo::save(QString &path)
{
    Component component(path);
    component.setPnumber(pNumberLineEdit->text());
    component.setSupplier(supplyLineEdit->text());
    component.setEngineer(engineerLineEdit->text());
    component.update();

    pNumberLineEdit->setEnabled(false);
    pNumberLineEdit->setStyleSheet("background-color:white; color:black");
    supplyLineEdit->setEnabled(false);
    supplyLineEdit->setStyleSheet("background-color:white; color:black");
    engineerLineEdit->setEnabled(false);
    engineerLineEdit->setStyleSheet("background-color:white; color:black");
}
