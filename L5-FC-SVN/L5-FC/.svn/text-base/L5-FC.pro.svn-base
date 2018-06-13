TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    appupdateviewer.cpp \
    qmlinterface.cpp

RESOURCES += \
    qml.qrc \
    images.qrc

DEFINES  += DEBUG_LOG
DEFINES += QT_MESSAGELOGCONTEXT
#DEFINES  += QT_NO_DEBUG_OUTPUT

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

VERSION = V1.0.0
VERSTR = '\\"$${VERSION}\\"'
DEFINES += VER=\"$${VERSTR}\" # create a VER macro containing the version string
win32: DTMSTR = '\\"$$system("echo %date% %time:~0,-3%")\\"'
unix:  DTMSTR = '\\"$$system(date "+%Y-%m-%d\ %H:%M:%S")\\"'
DEFINES += DTM=\"$${DTMSTR}\" # create a DTM macro containing the datetime string

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    appupdateviewer.h \
    qmlinterface.h \
    MW/mcu_agent_api.h

LIBS +=-L$${PWD}/MW -lmcu_agent

