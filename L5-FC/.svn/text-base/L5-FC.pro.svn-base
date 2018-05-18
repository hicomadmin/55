TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    appupdateviewer.cpp \
    qmlinterface.cpp

RESOURCES += \
    qml.qrc \
    images.qrc

DEFINES  += DEBUG_LOG
#DEFINES  += QT_NO_DEBUG_OUTPUT

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    appupdateviewer.h \
    qmlinterface.h \
    MW/mcu_agent_api.h

LIBS +=-L$${PWD}/MW -lmcu_agent

