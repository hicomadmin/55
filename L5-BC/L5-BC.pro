TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    appupdateviewer.cpp \
    qmlinterface.cpp \
    protocol/TheMcuAgent.cpp

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
    protocol/mcu_agent_api.h \
    protocol/TheMcuAgent.h

LIBS +=-L$${PWD}/protocol -lmcu_agent
message($${PWD})
