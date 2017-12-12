QT += core
QT += testlib
QT -= gui

CONFIG += qt
CONFIG += c++11

HEADERS = cmdprocessorbad.h \
    cmdprocessorgood.h \
    cmdprocessortemplate.h \
    icmdprocessor.h
SOURCES = testcmdprocessor.cpp \
    cmdprocessorbad.cpp \
    cmdprocessorgood.cpp \
    cmdprocessortemplate.cpp
