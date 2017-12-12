QT += core
QT += testlib
QT -= gui

CONFIG += qt
CONFIG += c++11

HEADERS = cmdprocessorbad.h \
    cmdprocessorgood.h
SOURCES = testcmdprocessor.cpp \
    cmdprocessorbad.cpp \
    cmdprocessorgood.cpp
