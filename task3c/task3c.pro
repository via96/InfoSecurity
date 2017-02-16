QT += core
QT -= gui

CONFIG += c++11

TARGET = task3c
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    converter.cpp

HEADERS += \
    converter.h
