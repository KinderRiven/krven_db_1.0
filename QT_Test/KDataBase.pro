# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = KDataBase
DESTDIR = ../Win32/Debug
QT += core multimedia sql network widgets gui multimediawidgets
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB QT_MULTIMEDIAWIDGETS_LIB QT_MULTIMEDIA_LIB QT_NETWORK_LIB QT_SQL_LIB
INCLUDEPATH += ../../../QT5.4.2/5.4/msvc2013_64/include \
    ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(KDataBase.pri)

FORMS += \
    onetableview.ui

HEADERS += \
    onetableview.h

SOURCES += \
    onetableview.cpp
