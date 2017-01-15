#include "contactinfo.h"
#include <QMessageBox>

ContactInfo::ContactInfo(QWidget *parent) : QWidget(parent)
{
    tableView = new QTableView;
    model = new QSqlTableModel(this);

    tableView->updatesEnabled();

    nameLineEdit = new QLineEdit;
    nameLineEdit->setPlaceholderText(tr("联系人"));
    companyLineEdit = new QLineEdit;
    companyLineEdit->setPlaceholderText(tr("公司"));

    searchBtn = new QPushButton(tr("查找"));
    addBtn = new QPushButton(tr("增加联系人"));
    deleteBtn = new QPushButton(tr("删除联系人"));
    submitAllBtn = new QPushButton(tr("提交"));

    connect(searchBtn, SIGNAL(clicked()), this, SLOT(search()));
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(deleteBtn, SIGNAL(clicked()), this, SLOT(deleteContact()));
    connect(submitAllBtn, SIGNAL(clicked()), this, SLOT(submitAll()));

    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addStretch(1);
    searchLayout->addWidget(nameLineEdit);
    searchLayout->addWidget(companyLineEdit);
    searchLayout->addWidget(searchBtn);
    searchLayout->addStretch(1);
    searchLayout->addWidget(addBtn);
    searchLayout->addWidget(deleteBtn);
    searchLayout->addWidget(submitAllBtn);

    mainLayout = new QVBoxLayout;
    //mainLayout->setMargin(10);
    //mainLayout->setSpacing(6);
    mainLayout->addLayout(searchLayout);


    model->setTable(QString("contacts"));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("电话"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("电子邮箱"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("固定电话"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("地址"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("邮编"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("公司"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("部门"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("职务"));


    tableView->setModel(model);
    tableView->resizeColumnsToContents();
    mainLayout->addWidget(tableView);
    setLayout(mainLayout);

}

void ContactInfo::search()
{
    QString name = nameLineEdit->text();
    QString company = companyLineEdit->text();
    if (name.isEmpty() && company.isEmpty())
    {
        model->setTable(tr("contacts"));
        model->select();
    }

    model->setFilter(QString("contacts.name='%1' or contacts.company='%2'").arg(name).arg(company));
    model->select();
}

void ContactInfo::addContact()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum, 0), tr(""));
}

void ContactInfo::deleteContact()
{
    int curRow = tableView->currentIndex().row();
    if (curRow > 0) {
        model->removeRow(curRow);
        int ok = QMessageBox::warning(this,
                                      tr("删除当前行！"),
                                      tr("确定删除当前行？"),
                                      QMessageBox::Yes,
                                      QMessageBox::No);
        if (ok == QMessageBox::No)
        {
            model->revertAll();
        } else
            model->submitAll();
    }

}

void ContactInfo::submitAll()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("保存联系人"),
                             tr("数据库报告一个错误: %1")
                             .arg(model->lastError().text()));
    }

}
