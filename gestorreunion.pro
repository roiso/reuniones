#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T18:27:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestorreunion
TEMPLATE = app


SOURCES += main.cpp\
    c_reunion.cpp \
    cargadatos.cpp \
    gestionaralumno.cpp \
    gestor.cpp \
    maincontroller.cpp \
    feha.cpp \
    c_alumno.cpp

HEADERS  += \
    c_alumno.h \
    cargadatos.h \
    gestionaralumno.h \
    gestor.h \
    interfaz.h \
    lista.h \
    maincontroller.h \
    c_reuniones.h \
    util.h \
    fecha.h

FORMS    += \
    gestionaralumno.ui \
    gestor.ui

CONFIG +=c++11
CONFIG +=debug
