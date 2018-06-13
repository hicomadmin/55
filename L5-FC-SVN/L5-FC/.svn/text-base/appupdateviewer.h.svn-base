#ifndef APPUPDATEVIEWER_H
#define APPUPDATEVIEWER_H
#include <QObject>


/**
 * @brief 界面视窗用于展示QML界面
 *
 */
class AppUpdateViewerPrivate;
class AppUpdateViewer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 界面视窗构造器
     *
     * @param parent
     */
    explicit AppUpdateViewer(QObject *parent = 0);

    /**
     * @brief 界面视窗析构器
     *
     */
    virtual ~AppUpdateViewer();

    /**
     * @brief 设置主入口QML文件
     *
     * @param 文件路径
     */
    void setMainQmlFile(const QString &file);

    /**
     * @brief 设置Import路径
     *
     * @param Import路径
     */
    void addImportPath(const QString &path);

    /**
     * @brief 设置QML对象
     *
     * @param 引用对象名
     * @param 对象指针
     */
    void setQmlObject(const QString &, QObject *);

    /**
     * @brief 设置QML对象
     *
     * @param 引用对象名
     * @param 对象值
     */
    void setQmlObject(const QString &, const QVariant &);

    /**
     * @brief 展示界面视窗
     *
     */
    void showExpanded();

signals:

public slots:

    /**
     * @brief 关闭界面视窗
     *
     */
    void close();

protected:
    AppUpdateViewerPrivate* const d_ptr;

private:
   Q_DECLARE_PRIVATE(AppUpdateViewer)

};


#endif // APPUPDATEVIEWER_H
