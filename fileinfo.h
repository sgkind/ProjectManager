#ifndef FILEINFO_H
#define FILEINFO_H

#include "treemodel.h"
#include "treeitem.h"
#include "pdetailinfo.h"
#include "cdetailinfo.h"
#include "sdetailinfo.h"
#include "cadetailinfo.h"
#include "filedetailinfo.h"
#include <QTreeView>
#include <QSqlQuery>
#include <QWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QFileInfo>
#include <QProcess>

class FileInfo : public QWidget
{
    Q_OBJECT
public:
    explicit FileInfo(QWidget *parent = 0);

private:
    QString contents;
    QTreeView *treeView;
    TreeModel *model;
    QStackedWidget *stack;

    QSqlQuery query;

    QHBoxLayout *mainLayout;

    QString queryContents();

    PDetailInfo *pDetailInfo;
    CDetailInfo *cDetailInfo;
    SDetailInfo *sDetailInfo;
    CADetailInfo *caDetailInfo;
    FileDetailInfo *fileDetailInfo;

    QPushButton *AMendBtn;
    QPushButton *SaveBtn;

    QHBoxLayout *BtnLayout;
    QVBoxLayout *RightLayout;

    QMenu *menu;

    void paint();
    void query_c(QString &contents, int p);
    void slotNew(QString title, QString tips, bool flag);
    QString convertPath(QString &path);

signals:

public slots:
    //左键单击
    void treeViewClick(const QModelIndex &index);
    void treeViewDoubleClick(const QModelIndex &index);
    //右键菜单
    void customContextMenu(const QPoint &);

    void slotNewProject();
    void slotNewComponent();
    void slotNewStage();
    void slotNewCategory();
    void slotRename();
    void slotDelete();
    void slotNewFile();

    void slotReplaceFile();
    void slotNewVersion();
    void openFolder();

    void edit();
    void save();
};

#endif // FILEINFO_H
