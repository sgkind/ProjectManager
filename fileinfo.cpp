#include "fileinfo.h"
#include "utility.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDateTime>
#include <QCoreApplication>

FileInfo::FileInfo(QWidget *parent) : QWidget(parent)
{


    treeView = new QTreeView(this);

    pDetailInfo = new PDetailInfo;
    cDetailInfo = new CDetailInfo;
    sDetailInfo = new SDetailInfo;
    caDetailInfo = new CADetailInfo;
    fileDetailInfo = new FileDetailInfo;
    stack = new QStackedWidget(this);
    stack->setFixedSize(600, 480);
    stack->setFrameStyle(QFrame::Panel | QFrame::Raised);
    stack->addWidget(pDetailInfo);
    stack->addWidget(cDetailInfo);
    stack->addWidget(sDetailInfo);
    stack->addWidget(caDetailInfo);
    stack->addWidget(fileDetailInfo);

    connect(treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(treeViewClick(const QModelIndex)));
    connect(treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(treeViewDoubleClick(const QModelIndex)));

    //创建修改按钮
    AMendBtn = new QPushButton(tr("修改"));
    SaveBtn = new QPushButton(tr("保存"));
    SaveBtn->setEnabled(false);
    connect(AMendBtn, SIGNAL(clicked()), this, SLOT(edit()));
    connect(SaveBtn, SIGNAL(clicked()), this, SLOT(save()));

    QHBoxLayout *BtnLayout = new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AMendBtn);
    BtnLayout->addWidget(SaveBtn);

    QVBoxLayout *RightLayout = new QVBoxLayout;
    RightLayout->addWidget(stack, 0, Qt::AlignHCenter);
    RightLayout->addLayout(BtnLayout);

    mainLayout = new QHBoxLayout(this);

    paint();
    connect(treeView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenu(QPoint)));

    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(treeView);
    mainLayout->addLayout(RightLayout);
}

void FileInfo::paint()
{
    QStringList headers;
    headers << tr("项目") << tr("描述");
    contents = queryContents();
    model = new TreeModel(headers, contents);
    treeView->setModel(model);

    treeView->setColumnHidden(1, true);
    //treeView开启右键菜单
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);

    treeView->setFixedSize(350, 520);
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

QString FileInfo::queryContents()
{
    QString r_contents = "";
    query_c(r_contents, 0);
    return r_contents;
}

void FileInfo::customContextMenu(const QPoint &)
{
    QModelIndex index = treeView->currentIndex();
    TreeItem *item = model->getItem(index);
    QString fileName = item->data(0).toString();

    menu = new QMenu;

    int i = item->data(1).toString().count('/');
    if (i == 1)
    {
        menu->addAction(QString(tr("新建项目")), this, SLOT(slotNewProject()));
        menu->addAction(QString(tr("添加电器件")), this, SLOT(slotNewComponent()));
    } else if(i == 2)
    {
        menu->addAction(QString(tr("添加新项目阶段")), this, SLOT(slotNewStage()));
    } else if(i == 3)
    {
        menu->addAction(QString(tr("添加文件类别")), this, SLOT(slotNewCategory()));
    } else if(i == 4)
    {
        menu->addAction(QString(tr("新建文档")), this, SLOT(slotNewFile()));
    } else if(i == 5)
    {
        menu->addAction(QString(tr("替换文档")), this, SLOT(slotReplaceFile()));
        menu->addAction(QString(tr("保存新版本")), this, SLOT(slotNewVersion()));
    }

    menu->addAction(QString(tr("重命名")), this, SLOT(slotRename()));
    menu->addAction(QString(tr("删除记录")), this, SLOT(slotDelete()));

    menu->exec(QCursor::pos());
}

void FileInfo::treeViewDoubleClick(const QModelIndex &index)
{
    TreeItem *item = model->getItem(index);
    QString s = item->data(1).toString();
    query.exec(QString("select address from files where path='%1'").arg(s));
    query.next();
    QString address = query.value(0).toString();
    int i = s.count('/');
    if (i == 5)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(address));
    }
}

void FileInfo::treeViewClick(const QModelIndex &index)
{
    TreeItem *item = model->getItem(index);
    QString s = item->data(1).toString();
    int i = s.count('/');
    if (i == 1)
    {
        Project project(s);
        QString name = item->data(0).toString();
        pDetailInfo->setContents(name, project);
    } else if (i == 2)
    {
        Component component(s);
        cDetailInfo->setContents(component);

    } else if (i == 3)
    {
        Stage stage(s);
        sDetailInfo->setContents(stage);
    } else if (i == 4)
    {
        Category category(s);
        caDetailInfo->setContents(category);
    } else if (i == 5) {
        File file(s);
        fileDetailInfo->setContents(file);
    }

    stack->setCurrentIndex(i - 1);
    AMendBtn->setEnabled(true);
}

void FileInfo::slotNew(QString title, QString tips, bool flag)
{
    query.exec(QString("select max(id) from items"));
        query.next();
        int index = query.value(0).toInt() + 1;

        QModelIndex modelIndex = treeView->currentIndex();
        TreeItem *item = model->getItem(modelIndex);
        QString string = item->data(1).toString();
        QString path = string + '/' + QString::number(index);

        query.exec(QString("select id from items where path='%1'").arg(string));
        query.next();
        int pid = query.value(0).toInt();

        bool ok;
        QString name = QInputDialog::getText(this, title, tips, QLineEdit::Normal, QString(""), &ok);
        if (flag) {
            QDateTime date = QDateTime::currentDateTime();
            QString dates = date.toString("yyyy-MM-dd");
            if(name.count('-')) {
               name += '-' + dates;
            } else {
                name += "-1-" + dates;
            }
        }
        if (ok && !name.isEmpty()) {
            query.exec(QString("insert into items values(NULL, '%1', '%2', '%3')").arg(name).arg(path).arg(pid));
        }
        int childCount = item->childCount();
        model->insertRows(childCount, 1, modelIndex);

        QModelIndex nowIndex0 = model->index(childCount, 0, modelIndex);
        model->setData(nowIndex0, name);
        QModelIndex nowIndex1 = model->index(childCount, 1, modelIndex);
        model->setData(nowIndex1, path);
        treeView->expand(modelIndex);
}

void FileInfo::slotNewProject()
{
    query.exec(QString("select max(id) from items"));
        query.next();
        int index = query.value(0).toInt() + 1;

        bool ok;
        QString name = QInputDialog::getText(this, tr("添加新项目"), tr("请输入项目名称："), QLineEdit::Normal, QString(""), &ok);
        QString path = '/' + QString::number(index);
        if (ok && !name.isEmpty()) {
            query.exec(QString("insert into items values(NULL, '%1','%2', 0)").arg(name).arg(path));
        }
        QModelIndex parent = treeView->currentIndex();
        TreeItem *item = model->getItem(parent);
        int childCount = item->childCount();
        model->insertRows(childCount, 1, parent);

        QModelIndex nowIndex0 = model->index(childCount, 0, parent);
        model->setData(nowIndex0, name);
        QModelIndex nowIndex1 = model->index(childCount, 1, parent);
        model->setData(nowIndex1, path);
}

void FileInfo::slotNewComponent()
{
    slotNew(tr("添加电器件"), tr("请输入电器件名称："), false);
}

void FileInfo::slotNewStage()
{
    slotNew(tr("项目阶段"), tr("请输入项目阶段名称："), false);
}

void FileInfo::slotNewCategory()
{
    slotNew(tr("文件类别"), tr("请输入文件类别名称:"), false);
}

void FileInfo::slotNewFile()
{
    slotNew(tr("新建文档"), tr("请输入文档名称："), true);
}

void FileInfo::slotRename()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString path = item->data(1).toString();
    QString oldName = item->data(0).toString();

    bool ok;
    QString name = QInputDialog::getText(this, tr("重命名"), tr("请输入新的名称："), QLineEdit::Normal, oldName, &ok);
    if (ok && !name.isEmpty()) {
        query.exec(QString("update items set name = '%1' where path = '%2'").arg(name).arg(path));
    }

    model->setData(modelIndex, name);
}

void FileInfo::slotDelete()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString path = item->data(1).toString();
    QString str = path + '%';

    query.exec(QString("delete from items where path like '%1'").arg(str));
    query.exec(QString("delete from projects where path like '%1'").arg(str));
    query.exec(QString("delete from components where path like '%1'").arg(str));
    query.exec(QString("delete from stages where path like '%1'").arg(str));
    query.exec(QString("delete from categories where path like '%1'").arg(str));
    query.exec(QString("delete from files where path like '%1'").arg(str));
    QModelIndex parent = model->parent(modelIndex);
    model->removeRows(item->childNumber(), 1, parent);
}

void FileInfo::slotReplaceFile()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString path = item->data(1).toString();

    QString wpath = convertPath(path);
    QDir targetDir(wpath);
    if (!targetDir.exists()) {
        if (!targetDir.mkpath(targetDir.absolutePath()))
        {
            QMessageBox::critical(this, tr("创建文件夹失败"), tr("创建文件夹失败，文件未保存"));
            return;
        }
    }

    QString name = QFileDialog::getOpenFileName(this, tr("选择文件"), tr("/"), tr("files (*)"));
    QFileInfo info(name);
    QString fileName = wpath + '/' + info.fileName();

    File file(path);
    if (!file.getAddress().isEmpty())
        QFile::remove(file.getAddress());

    QFile::copy(name, fileName);

    QDateTime date = QDateTime::currentDateTime();
    QString createTime = date.toString("yyyy-MM-dd hh:mm:ss");
    file.setCreate(createTime);
    file.setAddress(fileName);
    file.update();
}

void FileInfo::slotNewVersion()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString name = item->data(0).toString();
    QString string = item->data(1).toString();

    if (name.count('-') >= 3) {
        name = name.left(name.size() - 11);
    }
    if (name.count('-')) {
        int i = name.lastIndexOf('-');
        int version = name.right(name.size() - i - 1).toInt() + 1;
        name = name.left(i) + '-' + QString::number(version);
    }
    QDateTime date = QDateTime::currentDateTime();
    QString newName = name + date.toString("-yyyy-MM-dd");

    query.exec(QString("select pid from items where path='%1'").arg(string));
    query.next();
    int pid = query.value(0).toInt();

    query.exec(QString("insert into items values(NULL, '%1', '%2', '%3')").arg(newName).arg(QString("")).arg(pid));


    query.exec(QString("select max(id) from items"));
    query.next();
    int index = query.value(0).toInt();

    int ind = string.lastIndexOf('/');
    QString path = string.left(ind) + '/' + QString::number(index);

    QString wpath = convertPath(path);
    QDir targetDir(wpath);
    if (!targetDir.exists()) {
        if (!targetDir.mkpath(targetDir.absolutePath()))
        {
            QMessageBox::critical(this, tr("创建文件夹失败"), tr("创建文件夹失败，文件未保存"));
            return;
        }
    }

    query.exec(QString("update items set path='%1' where id='%2'").arg(path).arg(index));


    QModelIndex parent = model->parent(modelIndex);
    TreeItem *pitem = model->getItem(parent);
    int childCount = pitem->childCount();
    model->insertRows(childCount, 1, parent);

    QModelIndex nowIndex0 = model->index(childCount, 0, parent);
    model->setData(nowIndex0, newName);
    QModelIndex nowIndex1 = model->index(childCount, 1, parent);
    model->setData(nowIndex1, path);

    bool success = query.exec(QString("select createtime, address from files where path='%1'").arg(string));
    if (success && query.next()) {
        QString createTime = query.value(0).toString();
        QString address = query.value(1).toString();
        QFileInfo fileInfo(address);
        QString fileName = fileInfo.fileName();
        QString newAddress = wpath + fileName;

        File file(path);
        if (!file.getAddress().isEmpty())
            QFile::remove(file.getAddress());
        QFile::copy(address, newAddress);

        date = QDateTime::currentDateTime();
        QString modifyTime = date.toString("yyyy-MM-dd hh:mm:ss");
        file.setCreate(createTime);
        file.setModify(modifyTime);
        file.setAddress(newAddress);
        file.update();
    }
}

void FileInfo::openFolder()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString string = item->data(1).toString();

    query.exec(QString("select address from files where path='%1'").arg(string));
    query.next();
    QString address = query.value(0).toString();
    QFileInfo file(address);
    QString folderAddress = file.absolutePath();
    int i = string.count('/');
    if (i == 5)
    {
        folderAddress.replace("/", "\\");
        QProcess::startDetached("explorer " + folderAddress);
    }
}

void FileInfo::edit()
{
    if(AMendBtn->text() == tr("修改")){
        AMendBtn->setEnabled(false);
        SaveBtn->setEnabled(true);
        int index = stack->currentIndex();
        switch(index){
            case 0:
                pDetailInfo->editEnabled(); break;
            case 1:
                cDetailInfo->editEnabled(); break;
            case 2:
                sDetailInfo->editEnabled(); break;
            case 3:
                caDetailInfo->editEnabled(); break;
            case 4:
                fileDetailInfo->editEnabled(); break;

        }

    }
}

void FileInfo::save()
{
    QModelIndex modelIndex = treeView->currentIndex();
    TreeItem *item = model->getItem(modelIndex);
    QString path = item->data(1).toString();

    AMendBtn->setEnabled(true);
    SaveBtn->setEnabled(false);

    int index = stack->currentIndex();
    switch(index) {
        case 0:
            pDetailInfo->save(path); break;
        case 1:
            cDetailInfo->save(path); break;
        case 2:
            sDetailInfo->save(path); break;
        case 3:
            caDetailInfo->save(path); break;
        case 4:
            fileDetailInfo->save(path); break;
    }

}

void FileInfo::query_c(QString &contents, int p)
{
    QVector<int> temp;
    query.exec(QString("select * from items where pid='%1'").arg(p));
    while(query.next()) {
        temp << query.value(0).toInt();
    }
    if(temp.isEmpty())
        return;
    else
        foreach(int i, temp) {
            query.exec(QString("select * from items where id='%1'").arg(i));
            query.next();
            int size = query.value(2).toString().count('/');
            contents += QString((size-1) * 2, ' ');
            contents += query.value(1).toString();
            contents += "\t\t\t";
            contents += query.value(2).toString();
            contents += QString("\n");
            query_c(contents, i);
        }
}

QString FileInfo::convertPath(QString &path)
{
    QString wpath;
    wpath += QCoreApplication::applicationDirPath() + '/' + "Files";
    QStringList list = path.split('/');
    list.removeAt(0);
    foreach(QString s, list) {
        wpath += '/';
        query.exec(QString("select name from items where id='%1'").arg(s.toInt()));
        query.next();
        wpath += query.value(0).toString();
    }
    return wpath;
}


