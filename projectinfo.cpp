#include "projectinfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

ProjectInfo::ProjectInfo(QWidget *parent) : QWidget(parent)
{
    searchLabel = new QLabel(tr("搜索"));
    searchLineEdit = new QLineEdit();
    searchBtn = new QPushButton(tr("搜索"));

    projectTable = new QTableWidget;

    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addStretch(1);
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchBtn);

    QVBoxLayout *MainLayout = new QVBoxLayout(this);
    MainLayout->setMargin(10);
    MainLayout->setSpacing(6);
    MainLayout->addLayout(searchLayout);
    MainLayout->addWidget(projectTable);

}
