#ifndef QmlApplication_QmlApplication
#define QmlApplication_QmlApplication

#include <QmlApplication/QmlApplication_global.h>

#include <CoreApplication/Initializable.h>
#include <CoreApplication/CoreApplication.h>

#include <QtCore/QObject>

class QmlManager;
class QQmlContext;

class QMLAPPLICATION_EXPORT QmlApplication
	: public CoreApplication
{
	Q_OBJECT

public:

	QmlApplication();

	virtual ~QmlApplication();

	virtual qint32 execute();

	static QQmlContext* getCurrentQmlContext();

	static void loadQml(const QString& url);

	static QmlManager* getQmlManager();

protected:

	virtual void initializeInternal();

	virtual void endInitializeInternal();

	virtual void finalizeInternal();

private:

	static QmlApplication* mInstance;

	bool mFinalized;

	QmlManager* mQmlManager;

};

#endif
