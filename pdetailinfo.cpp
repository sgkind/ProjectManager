#include "pdetailinfo.h"

PDetailInfo::PDetailInfo(QWidget *parent) : QWidget(parent)
{
    projectNameLabel = new QLabel(tr("项目名："));
    projectCodeNameLabel = new QLabel(tr("项目代号："));
    OEMNameLabel = new QLabel(tr("主机厂:"));
    HVACEngineerLabel = new QLabel(tr("系统工程师："));
    electricianLabel = new QLabel(tr("电气工程师："));
    projectNameLineEdit = new QLineEdit;
    projectCodeNameLineEdit = new QLineEdit;
    OEMNameLineEdit = new QLineEdit;
    HVACEngineerLineEdit = new QLineEdit;
    electricianLineEdit = new QLineEdit;

    projectNameLineEdit->setEnabled(false);
    projectNameLineEdit->setStyleSheet("background-color:white; color:black");
    projectCodeNameLineEdit->setEnabled(false);
    projectCodeNameLineEdit->setStyleSheet("background-color:white; color:black");
    OEMNameLineEdit->setEnabled(false);
    OEMNameLineEdit->setStyleSheet("background-color:white; color:black");
    HVACEngineerLineEdit->setEnabled(false);
    HVACEngineerLineEdit->setStyleSheet("background-color:white; color:black");
    electricianLineEdit->setEnabled(false);
    electricianLineEdit->setStyleSheet("background-color:white; color:black");

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(projectNameLabel, 0, 0);
    mainLayout->addWidget(projectNameLineEdit, 0, 1);
    mainLayout->addWidget(projectCodeNameLabel, 1, 0);
    mainLayout->addWidget(projectCodeNameLineEdit, 1, 1);
    mainLayout->addWidget(HVACEngineerLabel, 2, 0);
    mainLayout->addWidget(HVACEngineerLineEdit, 2, 1);
    mainLayout->addWidget(electricianLabel, 3, 0);
    mainLayout->addWidget(electricianLineEdit, 3, 1);
    mainLayout->addWidget(OEMNameLabel, 4, 0);
    mainLayout->addWidget(OEMNameLineEdit, 4, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}

void PDetailInfo::setContents(QString &name, Project &project)
{
    projectNameLineEdit->setText(name);
    projectCodeNameLineEdit->setText(project.getCode());
    OEMNameLineEdit->setText(project.getOem());
    HVACEngineerLineEdit->setText(project.getHvac());
    electricianLineEdit->setText(project.getElectrician());
}

void PDetailInfo::editEnabled()
{
    projectNameLineEdit->setEnabled(true);
    projectCodeNameLineEdit->setEnabled(true);
    OEMNameLineEdit->setEnabled(true);
    HVACEngineerLineEdit->setEnabled(true);
    electricianLineEdit->setEnabled(true);
}

void PDetailInfo::save(QString &path)
{
    Project project(path);
    project.setCode(projectCodeNameLineEdit->text());
    project.setOem(OEMNameLineEdit->text());
    project.setHvac(HVACEngineerLineEdit->text());
    project.setElectrician(electricianLineEdit->text());
    project.update();

    projectNameLineEdit->setEnabled(false);
    projectNameLineEdit->setStyleSheet("background-color:white; color:black");
    projectCodeNameLineEdit->setEnabled(false);
    projectCodeNameLineEdit->setStyleSheet("background-color:white; color:black");
    OEMNameLineEdit->setEnabled(false);
    OEMNameLineEdit->setStyleSheet("background-color:white; color:black");
    HVACEngineerLineEdit->setEnabled(false);
    HVACEngineerLineEdit->setStyleSheet("background-color:white; color:black");
    electricianLineEdit->setEnabled(false);
    electricianLineEdit->setStyleSheet("background-color:white; color:black");
}
