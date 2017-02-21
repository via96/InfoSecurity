QT += core
QT -= gui

CONFIG += c++11

TARGET = task5c
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    filemanager.cpp \
    database.cpp

HEADERS += \
    filemanager.h \
    database.h
