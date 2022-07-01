#ifndef CoreApplication_CoreApplication
#define CoreApplication_CoreApplication

#include <CoreApplication/Initializable.h>
#include <CoreApplication/CoreApplication_global.h>

#include <QtCore/QObject>

class LogManager;
class PluginManager;
class SignalSlotManager;

class COREAPPLICATION_EXPORT CoreApplication
	: protected QObject
	, public Initializable
{
	Q_OBJECT

public:

	CoreApplication();

	virtual ~CoreApplication();

	virtual qint32 execute();

	virtual void initialize();

	virtual void finalize();

	static LogManager* getLogManager();

	static PluginManager* getPluginManager();

	static SignalSlotManager* getSignalSlotManager();

	static void registerSignal(const QString& eventName,
		QObject* sender,
		const char* signal);

	static void registerSlot(const QString& eventName,
		QObject* receiver,
		const char* slot,
		Qt::ConnectionType connectionType = Qt::AutoConnection);

	static void deregisterSignal(const QString& eventName,
		QObject* sender,
		const char* signal);

	static void deregisterSlot(const QString& eventName,
		QObject* receiver,
		const char* slot);

	static bool isInitialized();

protected:

	virtual void initializeInternal();

	virtual void endInitializeInternal();

	virtual void finalizeInternal();

private slots:

	void on_aboutToQuit();

private:

	void configureSettings();

	static CoreApplication* mInstance;

	LogManager* mLogManager;

	PluginManager* mPluginManager;

	SignalSlotManager* mSignalSlotManager;

	bool mInitialized;

	bool mFinalized;
};

#endif