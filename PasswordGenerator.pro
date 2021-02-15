#-------------------------------------------------
#
# Project created by QtCreator 2012-06-26T16:38:42
#
#-------------------------------------------------

QT       += core gui

TARGET = PasswordGenerator
TEMPLATE = app

CONFIG += static
CONFIG += frameworks_build
CONFIG += static_build

DEFINES += STATIC
DEFINES += STATIC_BUILD
RC_FILE += pwgen.rc


SOURCES += main.cpp\
        mainwindow.cpp \
    passwordgenerator.cpp \
    config.cpp

HEADERS  += mainwindow.h \
    passwordgenerator.h \
    config.h

FORMS    += mainwindow.ui

QMAKE_CFLAGS_RELEASE += /MT /Gy
QMAKE_CXXFLAGS_RELEASE += /MT /Gy

QMAKE_LFLAGS_RELEASE += /FORCE:MULTIPLE /NODEFAULTLIB:MSVCRTd.lib /DEFAULTLIB:LIBCMTd.lib /OPT:REF

win32 {
        RC_FILE += pwgen.rc
        CONFIG += static
        OBJECTS_DIR = build/o/win32
}

static_build {
    CONFIG += static

    DEFINES += STATIC
    DEFINES += STATIC_BUILD

    QMAKE_CFLAGS_RELEASE += /MT /Gy
    QMAKE_CXXFLAGS_RELEASE += /MT /Gy

    QMAKE_LFLAGS_RELEASE += /FORCE:MULTIPLE /NODEFAULTLIB:MSVCRT.lib /DEFAULTLIB:LIBCMT.lib /OPT:REF

    message("Static build.")
}

unix:!symbian|win32: LIBS += -L$$PWD/../../../C++/_Libs/tinyxml_2.6.2/Releasetinyxml/ -ltinyxml

INCLUDEPATH += $$PWD/../../../C++/_Libs/tinyxml_2.6.2
DEPENDPATH += $$PWD/../../../C++/_Libs/tinyxml_2.6.2

win32: PRE_TARGETDEPS += $$PWD/../../../C++/_Libs/tinyxml_2.6.2/Releasetinyxml/tinyxml.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../../../C++/_Libs/tinyxml_2.6.2/Releasetinyxml/libtinyxml.a
