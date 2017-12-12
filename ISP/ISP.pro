QT += core
QT += testlib
QT -= gui

CONFIG += qt
CONFIG += c++11

HEADERS = \
    settingsbad.h \
    settingsgood.h
SOURCES = \
    settingsbad.cpp \
    settingsgood.cpp \
    testsettings.cpp
