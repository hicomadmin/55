#include "appupdateviewer.h"

#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

class AppUpdateViewerPrivate{
    Q_DECLARE_PUBLIC(AppUpdateViewer)
public:
    AppUpdateViewerPrivate(AppUpdateViewer* parent) :
        q_ptr(parent),
        view(new QQuickView())
    {
        Q_Q(AppUpdateViewer);
        QObject::connect(view->engine(), SIGNAL(quit()), q, SLOT(close()));
        view->setResizeMode(QQuickView::SizeRootObjectToView);

    }

    AppUpdateViewer* q_ptr;
    QQuickView* view;
    QString mainQmlFile;
    static QString adjustPath(const QString &path);
};

QString AppUpdateViewerPrivate::adjustPath(const QString &path)
{
    QString pathInInstallDir = QString::fromLatin1("%1/../%2").arg(
                QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return QUrl(pathInInstallDir).toLocalFile();
    pathInInstallDir = QString::fromLatin1("%1/%2").arg(
                QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return QUrl(pathInInstallDir).toLocalFile();
    return path;
}

AppUpdateViewer::AppUpdateViewer(QObject *parent) :
    QObject(parent),d_ptr(new AppUpdateViewerPrivate(this))
{
}

AppUpdateViewer::~AppUpdateViewer()
{
    qInfo() << "==== Destruction AppUpdateViewer. ====";
    Q_D(AppUpdateViewer);
    delete d;
}

void AppUpdateViewer::setMainQmlFile(const QString &file)
{
    Q_D(AppUpdateViewer);
    d->mainQmlFile = AppUpdateViewerPrivate::adjustPath(file);
    //qDebug() << "1111" << d->mainQmlFile;
    d->view->setSource(QUrl(d->mainQmlFile));
}

void AppUpdateViewer::addImportPath(const QString &path)
{
    qDebug() << "==== addImportPath " << path;
    Q_D(AppUpdateViewer);
    d->view->engine()->addImportPath(AppUpdateViewerPrivate::adjustPath(path));
}

void AppUpdateViewer::setQmlObject(const QString &name, QObject *value)
{
    Q_D(AppUpdateViewer);
    d->view->rootContext()->setContextProperty(name, value);
}

void AppUpdateViewer::setQmlObject(const QString &name, const QVariant &value)
{
    Q_D(AppUpdateViewer);
    d->view->rootContext()->setContextProperty(name, value);
}

void AppUpdateViewer::showExpanded()
{
    Q_D(AppUpdateViewer);
#if defined(Q_WS_SIMULATOR) || defined(Q_OS_QNX)
    d->view->setFlags(Qt::Window|Qt::FramelessWindowHint);
    d->view->showFullScreen();
#else
    d->view->setFlags(Qt::Window|Qt::FramelessWindowHint);
    //d->view->setGeometry(0,0,1280,720);
    d->view->show();
#endif
}

void AppUpdateViewer::close()
{
    qDebug() << "==== Exit Application.";
    Q_D(AppUpdateViewer);
    d->view->close();
}
