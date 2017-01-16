#include "projectinfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

ProjectInfo::ProjectInfo(QWidget *parent) : QWidget(parent)
{
    tableView = new QTableView;
    model = new QSqlRelationalTableModel;

    model->setTable("items");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(2, QSqlRelation("path", "path", "code"));
    //model->setRelation(3, QSqlRelation("components"));

    model->setHeaderData(0, Qt::Horizontal, QString("项目名称"));
    model->setHeaderData(1, Qt::Horizontal, QString("项目代号"));
    model->setHeaderData(2, Qt::Horizontal, QString("件号"));
    model->select();

    tableView->setModel(model);

    nameLineEdit = new QLineEdit();
    nameLineEdit->setPlaceholderText(tr("项目名称"));
    codeLineEdit = new QLineEdit();
    codeLineEdit->setPlaceholderText(tr("项目代号"));
    componentLineEdit = new QLineEdit();
    componentLineEdit->setPlaceholderText(tr("电器件"));

    searchBtn = new QPushButton(tr("搜索"));

    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addStretch(1);
    searchLayout->addSpacing(5);
    searchLayout->addWidget(nameLineEdit);
    searchLayout->addWidget(codeLineEdit);
    searchLayout->addWidget(componentLineEdit);
    searchLayout->addWidget(searchBtn);

    QVBoxLayout *MainLayout = new QVBoxLayout(this);
    MainLayout->setMargin(10);
    MainLayout->setSpacing(6);
    MainLayout->addLayout(searchLayout);
    MainLayout->addWidget(tableView);

}

void ProjectInfo::search()
{

}
