#include "showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{
    splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splittrMain);
    list->insertItem(0, QObject::tr("基本信息"));


}
