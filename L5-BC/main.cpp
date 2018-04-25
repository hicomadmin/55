#include <QApplication>
#include <QThread>
#include <QDebug>
#include "appupdateviewer.h"
#include "qmlinterface.h"

#include <QFileInfo>
#include <QFile>
#include <QMutex>
#include <QDateTime>
#include <QString>

QmlInterface *g_QmlInterface = NULL;

void outputMessage(QtMsgType type, const QMessageLogContext&context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(static_cast<int>(type))
    {
    case QtDebugMsg:
       text = QString("Debug:");
       break;

    case QtWarningMsg:
       text = QString("Warning:");
       break;

    case QtCriticalMsg:
       text = QString("Critical:");
       break;

    case QtFatalMsg:
       text = QString("Fatal:");
    }

    QString context_info =QString("File:(%1)Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time =QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ssddd");
    QString current_date =QString("(%1)").arg(current_date_time);
    QString message =QString("%1 %2 %3%4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream <<message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 屏蔽文件qpnghandler.cpp的日志
    if(QString(context.file).indexOf("qpnghandler.cpp") > 0)
        return;

        QString msgFormat = "[ %Level% ][%current_date_time%][%File%] << %Message%";
        QString shellColor = "\e[33m";
        QString level = "Debug";
        //qint64 appId = QGuiApplication::applicationPid();
        QString current_date_time =QDateTime::currentDateTime().toString("hh:mm:ss.zzz ");
        switch (static_cast<int>(type)) {
        case QtDebugMsg:
            shellColor = "\e[32m";
            level = "Debug";
            break;
        case QtInfoMsg:
            shellColor = "\e[32m";
            level = "Info";
            break;
        case QtWarningMsg:
            shellColor = "\e[35m";
            level = "Warn";
            break;
        case QtCriticalMsg:
            shellColor = "\e[36m";
            level = "Critical";
            break;
        case QtFatalMsg:
            shellColor = "\e[31m";
            level = "Fatal";
            break;
        }
        msgFormat.replace("%Level%", level);
        //msgFormat.replace("%AppId%", QString::number(appId));
        msgFormat.replace("%current_date_time%", current_date_time);
        msgFormat.replace("%File%", QFileInfo(context.file).fileName().toLocal8Bit().constData());
        //msgFormat.replace("%Line%", QString::number(context.line));
        msgFormat.replace("%Message%", msg);

        printf("%s", msgFormat.toLocal8Bit().constData() );
        printf( "\n" );
        fflush(stdout);
    }

int main(int argc, char *argv[])
{
    //开启三级缓冲
    char env[] = "FB_MULTI_BUFFER=3";
    putenv(env);

    QApplication app(argc, argv);

    //注册MessageHandler
    qInstallMessageHandler(myMessageOutput);

    AppUpdateViewer viewer;
    g_QmlInterface = new QmlInterface;
    viewer.setQmlObject(QStringLiteral("c_qmlInterface"), g_QmlInterface);
    viewer.setMainQmlFile(QStringLiteral("qrc:/qml/main.qml"));
    viewer.showExpanded();

    qDebug() << "showExpanded main";

    return app.exec();
}

//加载图片中动画：
//originalImage.status != Image.Ready
