#include <QmlApplication/QmlApplication.h>
#include <QmlApplication/QmlManager.h>

QmlApplication* QmlApplication::mInstance = 0;

QmlApplication::QmlApplication()
	: CoreApplication()
	, mFinalized(false)
	, mQmlManager(0)
{
	if (0 == mInstance)
	{
		mInstance = this;
		mQmlManager = new QmlManager();
	}
}

QmlApplication::~QmlApplication()
{
	if (isInitialized())
	{
		if (!mFinalized)
		{
			finalize();
		}
	}

	delete mQmlManager;
}

void QmlApplication::initializeInternal()
{
	if (mInstance == this)
	{
		CoreApplication::initializeInternal();

		mQmlManager->initialize();		
	}
}

void QmlApplication::finalizeInternal()
{
	if (mInstance == this)
	{
		if (isInitialized())
		{
			mQmlManager->finalize();

			CoreApplication::finalizeInternal();
		}
	}
}

void QmlApplication::endInitializeInternal()
{
	CoreApplication::endInitializeInternal();

	if (mInstance == this)
	{
		mQmlManager->endInitialize();
	}
}

qint32 QmlApplication::execute()
{
	return CoreApplication::execute();
}

QQmlContext* QmlApplication::getCurrentQmlContext()
{
	QQmlContext* qmlContext = 0;

	if (0 != mInstance)
	{
		qmlContext = mInstance->mQmlManager->getCurrentContext();
	}

	return qmlContext;
}

void QmlApplication::loadQml(const QString& url)
{
	QmlManager* qmlManager = getQmlManager();
	if (0 != qmlManager)
	{
		qmlManager->loadContext(url);
	}
}

QmlManager* QmlApplication::getQmlManager()
{
	QmlManager* qmlManager = 0;

	if (0 != mInstance)
	{
		qmlManager = mInstance->mQmlManager;
	}

	return qmlManager;
}