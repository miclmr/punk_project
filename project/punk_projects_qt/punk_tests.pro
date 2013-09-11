######################################################################
# Automatically generated by qmake (2.01a) ?? 25. ??? 21:35:03 2013
######################################################################

*g++* : QMAKE_LFLAGS += -Wl,-z,origin \'-Wl,-rpath,\$\$ORIGIN/\'

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= QT

DEFINES += USE_OPENGL

TEMPLATE = app
TARGET = punk_tests

DEPENDPATH += . ..\..\source\tests\test_create_opengl_window
DEPENDPATH += . ..\..\source\tests\test_create_opengl_window

release:LIBPATH += ./../../bin/release
debug:LIBPATH += ./../../bin/debug

release:DESTDIR = ./../../bin/release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui

debug:DESTDIR = ./../../bin/debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui

win32 {
DEFINES += _WIN32
}



releas:MYDLLDIR = $$IN_PWD/../../../bin/release
debug:MYDLLDIR = $$IN_PWD/../../../bin/debug

# As our header files are in the same directory, we can make Qt Creator find it
# by specifying it as INCLUDEPATH.
INCLUDEPATH += $$MYDLLDIR

# Dependency to library domain (libdomain.so for Unices or domain.dll on Win32)
# Repeat this for more libraries if needed.
win32:LIBS += $$quote($$MYDLLDIR/domain.dll)
 unix:LIBS += $$quote(-L$$MYDLLDIR) -lpunk_engine -lX11


# Input
HEADERS += ../../source/tests/test_create_opengl_window/test_create_opengl_window.h \
           ../../source/tests/test_interface.h \
    ../../source/tests/test_clear_window/test_clear_buffer.h \
    ../../source/tests/test_first_triangle/firsttriangleandquad.h \    
    ../../source/tests/rotate_triangle.h \
    ../../source/tests/colored_triangle_test.h \
    ../../source/tests/test5.h \
    ../../source/tests/test6.h \
    ../../source/tests/test7.h \
    ../../source/tests/test8.h \
    ../../source/tests/test9.h \
    ../../source/tests/test3.h \
    ../../source/tests/test10.h \
    ../../source/tests/test11.cpp \
    ../../source/tests/test2.h \
    ../../source/tests/test12.h \
    ../../source/tests/test13.h \
    ../../source/tests/test14.h \
    ../../source/tests/test15.h \
    ../../source/tests/test16.h \
    ../../source/tests/test17.h \
    ../../source/tests/test18.h \
    ../../source/tests/test19.h \
    ../../source/tests/test20.h \
    ../../source/tests/test0.h \
    ../../source/tests/test21.h \
    ../../source/tests/test22.h

SOURCES += ../../source/tests/main.cpp \
           ../../source/tests/test_create_opengl_window/test_create_opengl_window.cpp \
    ../../source/tests/test_clear_window/test_clear_buffer.cpp \
    ../../source/tests/test_first_triangle/firsttriangleandquad.cpp \
    ../../source/tests/colored_triangle_test.cpp \
    ../../source/tests/rotate_triangle.cpp \
    ../../source/tests/test5.cpp \
    ../../source/tests/test6.cpp \
    ../../source/tests/test7.cpp \
    ../../source/tests/test8.cpp \
    ../../source/tests/test9.cpp \
    ../../source/tests/test3.cpp \
    ../../source/tests/test10.cpp \
    ../../source/tests/test11.cpp \
    ../../source/tests/test2.cpp \
    ../../source/tests/test12.cpp \
    ../../source/tests/test13.cpp \
    ../../source/tests/test14.cpp \
    ../../source/tests/test15.cpp \
    ../../source/tests/test16.cpp \
    ../../source/tests/test17.cpp \
    ../../source/tests/test18.cpp \
    ../../source/tests/test19.cpp \
    ../../source/tests/test20.cpp \
    ../../source/tests/test0.cpp \
    ../../source/tests/test21.cpp \
    ../../source/tests/test22.cpp
