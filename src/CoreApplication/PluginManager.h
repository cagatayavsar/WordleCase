#ifndef CoreApplication_PluginManager
#define CoreApplication_PluginManager

#include <CoreApplication/PluginTypes.h>
#include <CoreApplication/Initializable.h>
#include <CoreApplication/CoreApplication_global.h>

#include <QtCore/QObject>
#include <QtCore/QVector>

class QSettings;

class COREAPPLICATION_EXPORT PluginManager
	: public QObject
	, public Initializable
{
	Q_OBJECT

public:

	PluginManager();

	virtual ~PluginManager();

	virtual void initialize();

	virtual void endInitialize();

	virtual void finalize();

	PluginVector getPlugins() const;

signals:

	void loadingPlugin(QString pluginName);

private:

	void loadPlugins();

	void loadPlugin(const QString& pluginName, QSettings &settings);

	void beginInitialize();

	void initializePlugins();

	void finalizePlugins();

	void unloadPlugins();

	PluginHashMap mPluginMap;

};
#endif