#include <CoreApplication/CoreApplication.h>
#include <CoreApplication/LogManager.h>
#include <CoreApplication/PluginManager.h>
#include <CoreApplication/SignalSlotManager.h>
#include <CoreApplication/XmlSettingsFormat.h>

#include <QtCore/QDebug>
#include <QtCore/QSettings>
#include <QtCore/QFileInfo>
#include <QtCore/QCoreApplication>

CoreApplication* CoreApplication::mInstance = 0;

CoreApplication::CoreApplication()
	: mLogManager(0)
	, mPluginManager(0)
	, mSignalSlotManager(0)
	, mInitialized(false)
	, mFinalized(false)
{
	if (0 == mInstance)
	{
		mInstance = this;

		connect(QCoreApplication::instance(),
			SIGNAL(aboutToQuit()),
			this,
			SLOT(on_aboutToQuit()));

		mSignalSlotManager = new SignalSlotManager();
		mLogManager = new LogManager();
		mPluginManager = new PluginManager();

		configureSettings();
	}
}

CoreApplication::~CoreApplication()
{
}

qint32 CoreApplication::execute()
{
	int result = -1;
	try
	{
		result = qApp->exec();
	}
	catch (std::exception& stdException)
	{
		qWarning() << "Unhandled STL Exception" << stdException.what();
	}
	catch (...)
	{
		qWarning() << "Unhandled Exception" << "Unknown Exception";
	}
	return result;
}

void CoreApplication::initialize()
{
	initializeInternal();
	mInitialized = true;
	mFinalized = false;
	endInitializeInternal();
}

void CoreApplication::finalize()
{
	finalizeInternal();
	mInitialized = false;
	mFinalized = true;
}

LogManager * CoreApplication::getLogManager()
{
	LogManager* logManager = 0;

	if (0 != mInstance)
	{
		logManager = mInstance->mLogManager;
	}

	return logManager;
}

PluginManager * CoreApplication::getPluginManager()
{
	PluginManager* pluginManager = 0;

	if (0 != mInstance)
	{
		pluginManager = mInstance->mPluginManager;
	}

	return pluginManager;
}

SignalSlotManager * CoreApplication::getSignalSlotManager()
{
	SignalSlotManager* signalSlotManager = 0;

	if (0 != mInstance)
	{
		signalSlotManager = mInstance->mSignalSlotManager;
	}

	return signalSlotManager;
}

void CoreApplication::registerSignal(const QString & eventName, QObject * sender, const char * signal)
{
	if (0 != mInstance)
	{
		mInstance->mSignalSlotManager->registerSignal(eventName, sender, signal);
	}
}

void CoreApplication::registerSlot(const QString & eventName, QObject * receiver, const char * slot, Qt::ConnectionType connectionType)
{
	if (0 != mInstance)
	{
		mInstance->mSignalSlotManager->registerSlot(eventName, receiver, slot, connectionType);
	}
}

void CoreApplication::deregisterSignal(const QString & eventName, QObject * sender, const char * signal)
{
	if (0 != mInstance)
	{
		mInstance->mSignalSlotManager->deregisterSignal(eventName, sender, signal);
	}
}

void CoreApplication::deregisterSlot(const QString & eventName, QObject * receiver, const char * slot)
{
	if (0 != mInstance)
	{
		mInstance->mSignalSlotManager->deregisterSlot(eventName, receiver, slot);
	}
}

bool CoreApplication::isInitialized()
{
	bool initialized = false;

	if (0 != mInstance)
	{
		initialized = mInstance->mInitialized;
	}

	return initialized;
}

void CoreApplication::initializeInternal()
{
	if (mInstance == this)
	{
		mLogManager->initialize();
		mPluginManager->initialize();
		mSignalSlotManager->initialize();
	}
}

void CoreApplication::endInitializeInternal()
{
	if (mInstance == this)
	{
		mLogManager->endInitialize();
		mPluginManager->endInitialize();
		mSignalSlotManager->endInitialize();
	}
}

void CoreApplication::finalizeInternal()
{
	if (mInstance == this)
	{
		mLogManager->finalize();
		mPluginManager->finalize();
		mSignalSlotManager->finalize();
	}
}

void CoreApplication::configureSettings()
{
	QSettings::Format xmlFormat = QSettings::registerFormat("xml",
		XmlSettingsFormat::readXml,
		XmlSettingsFormat::writeXml);

	QSettings::setDefaultFormat(xmlFormat);
	QString path = QCoreApplication::applicationDirPath();
	QSettings::setPath(xmlFormat, QSettings::SystemScope, path);

	QString applicationFilePath = QCoreApplication::applicationFilePath();
	QString name = QFileInfo(applicationFilePath).baseName();

	QCoreApplication::setOrganizationName(name);
}

void CoreApplication::on_aboutToQuit()
{
	finalize();
}
