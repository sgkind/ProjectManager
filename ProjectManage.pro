#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T22:34:47
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectManage
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    logindialog.cpp \
    projectinfo.cpp \
    treeitem.cpp \
    treemodel.cpp \
    fileinfo.cpp \
    pdetailinfo.cpp \
    cdetailinfo.cpp \
    sdetailinfo.cpp \
    cadetailinfo.cpp \
    filedetailinfo.cpp \
    contactinfo.cpp \
    utility.cpp \
    changepassword.cpp

HEADERS  += mainwindow.h \
    widget.h \
    connection.h \
    logindialog.h \
    projectinfo.h \
    treeitem.h \
    treemodel.h \
    fileinfo.h \
    pdetailinfo.h \
    cdetailinfo.h \
    sdetailinfo.h \
    cadetailinfo.h \
    filedetailinfo.h \
    contactinfo.h \
    utility.h \
    changepassword.h

FORMS += \
    logindialog.ui

RESOURCES += \
    project.qrc
