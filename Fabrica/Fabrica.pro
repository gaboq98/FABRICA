#-------------------------------------------------
#
# Project created by QtCreator 2017-10-02T16:32:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fabrica
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    almacen.cpp \
    nodo.cpp \
    mezcladorachocolate.cpp \
    mezcladoramasa.cpp \
    cola.cpp \
    almacenfinal.cpp \
    horno.cpp \
    camion.cpp \
    configuracion.cpp \
    mainthread.cpp \
    mezcladorasthread.cpp \
    ensambladorathread.cpp \
    ensambladora.cpp \
    controlcalidad.cpp \
    inspector.cpp \
    empacadora.cpp \
    controlcalidadthread.cpp \
    empacadorathread.cpp

HEADERS += \
        mainwindow.h \
    almacen.h \
    camion.h \
    nodo.h \
    mezcladorachocolate.h \
    mezcladoramasa.h \
    cola.h \
    camion.h \
    almacenfinal.h \
    horno.h \
    configuracion.h \
    mainthread.h \
    mezcladorasthread.h \
    ensambladora.h \
    ensambladorathread.h \
    controlcalidad.h \
    inspector.h \
    empacadora.h \
    controlcalidadthread.h \
    empacadorathread.h

FORMS += \
        mainwindow.ui \
    configuracion.ui

RESOURCES += \
    imagenes.qrc
