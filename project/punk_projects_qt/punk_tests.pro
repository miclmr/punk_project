######################################################################
# Automatically generated by qmake (2.01a) ?? 25. ??? 21:35:03 2013
######################################################################

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= QT

DEFINES += _WIN32

TEMPLATE = app
TARGET = punk_tests

DEPENDPATH += . ..\..\source\tests\test_create_opengl_window
DEPENDPATH += . ..\..\source\tests\test_create_opengl_window

Release:LIBPATH += ./../../bin/release
Debug:LIBPATH += ./../../bin/release

LIBS += -lpunk_engine

Release:DESTDIR = ./../../bin/release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = ./../../bin/debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

# Input
HEADERS += ../../source/tests/test_create_opengl_window/test_create_opengl_window.h \
           ../../source/tests/test_interface.h \

SOURCES += ../../source/tests/main.cpp \
           ../../source/tests/test_create_opengl_window/test_create_opengl_window.cpp \

