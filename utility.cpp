#include "utility.h"
#include <QDebug>
#include <QSqlError>
#include <QDebug>

utility::utility()
{

}

bool User::user_query(QString name, QString password)
{
    bool success = query.exec(QString("select password from users where name = '%1'").arg(name));
    if (success && query.next()) {
        if(query.value(0).toString() == password) {
            return true;
        }
        else
            return false;
    } else
    {
        return false;
    }
}

bool User::update_password(QString name, QString password, QString newPassword)
{
    bool success = query.exec(QString("select password from users where name = '%1'").arg(name));
    if (success && query.next()) {
        if (query.value(0).toString() != password) {
            return false;
        }
        else {
            bool flag = query.exec(QString("update users set password = '%1' where name = '%2'").arg(newPassword).arg(name));
            if (flag)
                return true;
            else
                return false;
        }
    }
    return false;
}

Project::Project(QString &wpath)
{
    path = wpath;
    bool success = query.exec(QString("select id, code, oem, hvac, electrician from projects where path = '%1'").arg(path));
    if (success && query.next()) {
        id = query.value(0).toInt();
        code = query.value(1).toString();
        oem = query.value(2).toString();
        hvac = query.value(3).toString();
        electrician = query.value(4).toString();
    }
}

bool Project::update()
{
    bool success = query.exec(QString("select * from projects where path = '%1'").arg(path));
    if (success && query.next())
    {
        QString tcode = query.value(2).toString();
        QString toem = query.value(3).toString();
        QString thvac = query.value(4).toString();
        QString telectrician = query.value(5).toString();
        if (tcode != code)
            query.exec(QString("update projects set code='%1' where path='%2'").arg(code).arg(path));
        if (toem != oem)
            query.exec(QString("update projects set oem='%1' where path='%2'").arg(oem).arg(path));
        if (thvac != hvac)
            query.exec(QString("update projects set hvac='%1' where path='%2'").arg(hvac).arg(path));
        if (telectrician != electrician)
            query.exec(QString("update projects set electrician='%1' where path='%2'").arg(electrician).arg(path));
        return true;
    }

    return query.exec(QString("insert into projects values(NULL, '%1', '%2', '%3','%4', '%5')").arg(path).arg(code).arg(oem).arg(hvac).arg(electrician));
}

Component::Component(QString &wpath)
{
    path = wpath;
    bool success = query.exec(QString("select id, pnumber, supplier, engineer from components where path='%1'").arg(path));
    if (success && query.next()) {
        id = query.value(0).toInt();
        pnumber = query.value(1).toString();
        supplier = query.value(2).toString();
        engineer = query.value(3).toString();
    }
}

bool Component::update()
{
    bool success = query.exec(QString("select * from components where path = '%1'").arg(path));
    if (success && query.next()) {
        QString tpnumber = query.value(2).toString();
        QString tsupplier = query.value(3).toString();
        QString tengineer = query.value(4).toString();
        if (tpnumber != pnumber)
            query.exec(QString("update components set pnumber='%1' where path='%2'").arg(pnumber).arg(path));
        if (tsupplier != supplier)
            query.exec(QString("update components set supplier='%1' where path='%2'").arg(supplier).arg(path));
        if (tengineer != engineer)
            query.exec(QString("update components set engineer='%1' where path='%2'").arg(engineer).arg(path));
        return true;
    }
    qDebug() << query.exec(QString("insert into components values(NULL, '%1', '%2', '%3', '%4')").arg(path).arg(pnumber).arg(supplier).arg(engineer));
    return  true;
}

Stage::Stage(QString &wpath)
{
    path = wpath;
    bool success = query.exec(QString("select id, note from stages where path = '%1'").arg(path));
    if (success && query.next()) {
        id = query.value(0).toInt();
        note = query.value(1).toString();
    }
}

bool Stage::update()
{
    if(path.isEmpty())
        return false;
    bool success = query.exec(QString("select * from stages where path='%1'").arg(path));
    if (success && query.next()) {
        QString tnote = query.value(2).toString();
        if (tnote != note)
            query.exec(QString("update stages set note='%1' where path='%2'").arg(note).arg(path));
        return true;
    }
    return query.exec(QString("insert into stages values(NULL, '%1', '%2')").arg(path).arg(note));
}

Category::Category(QString &wpath)
{
    path = wpath;
    bool success = query.exec(QString("select id, note from categories where path='%1'").arg(path));
    if (success && query.next()) {
        id = query.value(0).toInt();
        note = query.value(1).toString();
    }
}

bool Category::update()
{
    if(path == QString(""))
        return false;
    bool success = query.exec(QString("select * from categories where path='%1'").arg(path));
    if (success && query.next())
    {
        QString tnote = query.value(2).toString();
        if (tnote != note)
            query.exec(QString("update categories set note='%1' where path='%2'").arg(note).arg(path));
        return true;


    }
    return query.exec(QString("insert into categories values(NULL, '%1', '%2')").arg(path).arg(note));
}

File::File(QString &wpath)
{
    path = wpath;
    bool success = query.exec(QString("select id, createtime, modifytime, note, address from files where path='%1'").arg(path));
    if (success && query.next()) {
        id = query.value(0).toInt();
        create = query.value(1).toString();
        modify = query.value(2).toString();
        note = query.value(3).toString();
        address = query.value(4).toString();
    }
}

bool File::update()
{
    bool success = query.exec(QString("select * from files where path = '%1'").arg(path));
    if (success && query.next())
    {
        QString tcreate = query.value(2).toString();
        QString tmodify = query.value(3).toString();
        QString tnote  = query.value(4).toString();
        QString taddress = query.value(5).toString();
        if (tcreate != create)
            query.exec(QString("update files set createtime='%1' where path='%2'").arg(create).arg(path));
        if (tmodify != modify)
            query.exec(QString("update files set modifytime='%1' where path='%2'").arg(modify).arg(path));
        if (tnote != note)
            query.exec(QString("update files set note='%1' where path='%2'").arg(note).arg(path));
        if (taddress != address)
            query.exec(QString("update files set address='%1' where path='%2'").arg(address).arg(path));
        return true;
    }

    return query.exec(QString("insert into files values(NULL, '%1', '%2', '%3', '%4', '%5')").arg(path).arg(create).arg(modify).arg(note).arg(address));

}


