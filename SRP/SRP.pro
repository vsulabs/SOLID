QT += core
QT += testlib
QT -= gui

CONFIG += qt
CONFIG += c++11

HEADERS = textcorrectorgood.h \
    textcorrectorbad.h

SOURCES = testtextcorrector.cpp \
    textcorrectorgood.cpp \
    textcorrectorbad.cpp
