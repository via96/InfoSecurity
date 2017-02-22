QT += core
QT -= gui

CONFIG += c++11

TARGET = task4c
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    converter.cpp \
    filemanager.cpp

HEADERS += \
    converter.h \
    filemanager.h
