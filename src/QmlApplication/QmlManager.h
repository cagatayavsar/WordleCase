#ifndef QmlApplcation_QmlManager
#define QmlApplcation_QmlManager

#include <QtCore/QObject>

#include <CoreApplication/Initializable.h>

class QQmlApplicationEngine;
class QQmlContext;

class QmlManager
	: public QObject
	, public Initializable
{
	Q_OBJECT

public:

	QmlManager();

	virtual void initialize();

	virtual void finalize();

	virtual void endInitialize();

	QQmlContext* getCurrentContext();

	void loadContext(const QString& url);

signals:

	void emitQmlContextCreated(QQmlContext* qmlContext);

	void beforeQmlContextCreated(QQmlContext* qmlContext);

private slots:

	void objectCreated(QObject* object, const QUrl& url);

private:

	QQmlApplicationEngine* mEngine;
};

#endif