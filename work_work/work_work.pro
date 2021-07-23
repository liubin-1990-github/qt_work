#-------------------------------------------------
#
# Project created by QtCreator 2021-07-19T20:22:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = work_work
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
    thread_sever.cpp \
    mybutton.cpp \
    current_data_tree_widget.cpp \
    current_data_tree_view.cpp \
    alarmmodel.cpp \
    alarmview.cpp

HEADERS += \
        mainwindow.h \
    thread_sever.h \
    mybutton.h \
    current_data_tree_widget.h \
    current_data_tree_view.h \
    alarmmodel.h \
    alarmview.h

FORMS += \
        mainwindow.ui
