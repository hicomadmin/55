#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QString>


class QmlInterface : public QObject
{
    Q_OBJECT
public:
    explicit QmlInterface(QObject *parent = 0);

    Q_INVOKABLE void  qmlDebug(QString str, int val = -1);


signals:

public slots:

};

#endif // QMLINTERFACE_H
