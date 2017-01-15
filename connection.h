#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("project.db");
    db.setUserName("sunguanke");
    db.setPassword("123456");
    if(!db.open()){
        return false;
    }

    QSqlQuery query;

    //用户数据表
    query.exec("create table users(id int primary key, name varchar(20) unique, password varchar(32))");
    query.exec("insert into users (id, name, password) values (1, 'sunguanke', '123456')");

    //测试表
    query.exec("create table items(id integer primary key , name varchar(100), path varchar(50) unique, pid integer)");
    query.exec(QString("insert into items values(1, 'S25', '/1', 0)"));
    query.exec(QString("insert into items values(2, '除霜温度传感器', '/1/2', 1)"));
    query.exec(QString("insert into items values(3, '鼓风机', '/1/3', 1)"));
    query.exec(QString("insert into items values(4, '用户输入', '/1/2/4', 2)"));
    query.exec(QString("insert into items values(5, 'SOR', '/1/2/5', 2)"));
    query.exec(QString("insert into items values(6, 'SOR文件', '/1/2/5/6', 5)"));
    query.exec(QString("insert into items values(7, '2D图纸', '/1/2/5/7', 5)"));
    query.exec(QString("insert into items values(8, 'M50N', '/8', 0)"));
    query.exec(QString("insert into items values(9, '超航图纸-2016-01-05', '/1/2/5/7/9', 7)"));
    query.exec(QString("insert into items values(10, 'M39', '/10', 0)"));


    //创建项目表
    query.exec("create table projects(id int primary key, path varchar(1000), code varchar(100), oem varchar(100), hvac varchar(20), electrician varchar(20))");
    query.exec(QString("insert into projects values(1, '/1', '6019', '北汽银翔', '孙观课', '王')"));
    query.exec(QString("insert into projects values(2, '/8', '1405', '北汽银翔', '孙观', 'ta')"));

    //创建电器件
    query.exec("create table components(id int primary key, path varchar(1000), pnumber varchar(20), supplier varchar(20), engineer varchar(20))");
    query.exec(QString("insert into components values(1, '/1/3', '6010011602', '苏州睿动','郑伟') "));

    //创建项目阶段
    query.exec("create table stages(id int primary key, path varchar(1000), note text)");
    query.exec(QString("insert into stages values(1, '/1/2/4', '这个是一个备注')"));

    //创建类别
    query.exec("create table categories(id int primary key, path varchar(1000), note text)");
    query.exec(QString("insert into categories values(1, '/1/2/5/7', '这是另一个备注')"));


    //创建文件
    query.exec("create table files(id int primary key, path varchar(1000), createtime datetime, modifytime datetime, note text, address varchar(200))");
    query.exec(QString("insert into files values(1, '/1/2/5/7/9', '2006-10-17 00:20:00', '2006-10-17 00:20:00', '这是有一个标注', 'E:\1\2\5\7\11\1.txt')"));

    //创建联系人
    query.exec("create table contacts (id int primary key, name varchar(20), phone varchar(20), email varchar(40), telephone varchar(20), address varchar(40), post varchar(10), company varchar(40), department varchar(10), position varchar(20))");
    query.exec(QString("insert into contacts values(1, '孙冠珂', '15051877834', 'sguanke@163.com', '025-12345678', '南京市江宁区天元东路228号', '012345', 'sgkind', '办公司', 'ceo')"));
    query.exec(QString("insert into contacts values(2, 'sgk', '17326100153', 'sunguanke@163.com', '025-12345678', '河南省郏县安良镇任庄', '010111', 'sgkind', '研发部', 'cfo')"));

    return true;
}

#endif // CONNECTION_H
