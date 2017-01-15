#ifndef UTILITY_H
#define UTILITY_H

#include <QString>
#include <QSqlQuery>



class utility
{
public:
    utility();
};

class User
{
public:
    User(){}

    bool user_query(QString name, QString password);
    bool update_password(QString name, QString password, QString newPassword);
    //QString get_password() { return password;}


private:
    QSqlQuery query;
    int id;
    QString username;
    QString password;
};

class Project
{
public:
    Project(){}
    Project(QString &path);

    void setPath(QString wpath) {path = wpath;}
    void setCode(QString wcode) {code = wcode;}
    void setOem(QString woem) {oem = woem;}
    void setHvac(QString whvac) {hvac = whvac; }
    void setElectrician(QString welectrician) { electrician = welectrician; }

    int getId() {return id;}
    QString getPath() { return path;}
    QString getCode() { return code; }
    QString getOem() { return oem; }
    QString getHvac() { return hvac; }
    QString getElectrician() { return electrician; }

    bool update();

private:
    QSqlQuery query;
    int id;
    QString path;
    QString code;
    QString oem;
    QString hvac;
    QString electrician;

};

class Component
{
public:
    Component() {}
    Component(QString &path);

    void setPath(QString wpath) { path = wpath; }
    void setPnumber(QString wpnumber) { pnumber = wpnumber; }
    void setSupplier(QString wsupplier) { supplier = wsupplier; }
    void setEngineer(QString wengineer) { engineer = wengineer; }

    int getId() { return id;}
    QString getPath() { return path; }
    QString getPnumber() { return pnumber; }
    QString getSupplier() { return supplier; }
    QString getEngineer() { return engineer; }

    bool update();

private:
    QSqlQuery query;
    int id;
    QString path;
    QString pnumber;
    QString supplier;
    QString engineer;
};

class Stage
{
public:
    Stage() {}
    Stage(QString &path);

    void setPath(QString wpath) { path = wpath; }
    void setNote(QString wnote) { note = wnote; }

    int getId() { return id; }
    QString getPath() { return path; }
    QString getNote() { return note; }

    bool update();

private:
    QSqlQuery query;
    int id;
    QString path;
    QString note;
};

class Category
{
public:
    Category(){}
    Category(QString &path);

    void setPath(QString wpath) { path = wpath; }
    void setNote(QString wnote) { note = wnote; }

    int getId() { return id; }
    QString getPath() { return path; }
    QString getNote() { return note; }

    bool update();

private:
    QSqlQuery query;
    int id;
    QString path;
    QString note;
};

class File
{
public:
    File(){}
    File(QString &wpath);

    void setPath(QString wpath) {path = wpath;}
    void setCreate(QString wcreate) {create = wcreate;}
    void setModify(QString wmodify) {modify = wmodify;}
    void setNote(QString wnote) {note = wnote;}
    void setAddress(QString waddress) {address = waddress;}

    int getId() {return id;}
    QString getCreate() {return create;}
    QString getModify() {return modify;}
    QString getNote() {return note;}
    QString getAddress() {return address;}

    bool update();


private:
    QSqlQuery query;
    int id;
    QString path;
    QString create;
    QString modify;
    QString note;
    QString address{};

};

#endif // UTILITY_H
