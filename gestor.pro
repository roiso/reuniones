#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T16:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    c_alumno.cpp \
    c_user.cpp \
    cargadatos.cpp \
    log.cpp \
    maincontroller.cpp \
    c_reunion.cpp \
    gestor.cpp \
    gestionaralumno.cpp

HEADERS  += mainwindow.h \
    c_alumno.h \
    c_user.h \
    cargadatos.h \
    interfaz.h \
    lista.h \
    log.h \
    maincontroller.h \
    c_reunion.h \
    gestor.h \
    gestionaralumno.h

CONFIG += c++11
CONFIG +=debug

FORMS    += mainwindow.ui \
    gestor.ui \
    gestionaralumno.ui

