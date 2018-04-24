#include "qmlinterface.h"
#include <QDebug>

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{


}

void QmlInterface::qmlDebug(QString str, int val)
{
#if DEBUG_LOG
    if(val == -1)
        qDebug() << "[qml] ##### " << str;
    else
        qDebug() << "[qml] ##### " << str << ":" << val;
#endif
}
