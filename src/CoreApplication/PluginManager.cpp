#include <CoreApplication/PluginManager.h>
#include <CoreApplication/CoreApplication.h>

#include <QtCore/QtDebug>
#include <QtCore/QSettings>
#include <QtCore/QPluginLoader>
#include <QtCore/QCoreApplication>

PluginManager::PluginManager()
{
	CoreApplication::registerSignal(
		"LoadingPluginEvent",
		this,
		SIGNAL(loadingPlugin(QString)));
}

PluginManager::~PluginManager()
{
}

void PluginManager::initialize()
{
	loadPlugins();
	beginInitialize();
	initializePlugins();
}

void PluginManager::beginInitialize()
{
	PluginHashMap::iterator itr;
	for (itr = mPluginMap.begin(); itr != mPluginMap.end(); ++itr)
	{
		Plugin* plugin = itr.value();
		plugin->beginInitialize();
	}
}

void PluginManager::initializePlugins()
{
	PluginHashMap::iterator itr;
	for (itr = mPluginMap.begin(); itr != mPluginMap.end(); ++itr)
	{
		Plugin* plugin = itr.value();
		plugin->initialize();
	}
}

void PluginManager::endInitialize()
{
	PluginHashMap::iterator itr;
	for (itr = mPluginMap.begin(); itr != mPluginMap.end(); ++itr)
	{
		Plugin* plugin = itr.value();
		plugin->endInitialize();
	}
}

void PluginManager::finalize()
{
	finalizePlugins();
	unloadPlugins();
}

void PluginManager::finalizePlugins()
{
	PluginHashMap::iterator itr;
	for (itr = mPluginMap.begin(); itr != mPluginMap.end(); ++itr)
	{
		Plugin* plugin = itr.value();
		plugin->finalize();
	}
}

void PluginManager::unloadPlugins()
{
	mPluginMap.clear();
}

PluginVector PluginManager::getPlugins() const
{
	PluginList pluginList = mPluginMap.values();
	PluginVector pluginVector;

	foreach (Plugin* plugin, pluginList)
	{
		pluginVector.push_back(plugin);
	}

	return pluginVector;
}

void PluginManager::loadPlugins()
{
	QSettings settings;
	settings.beginGroup("Plugins");

	if (QSettings::NoError == settings.status())
	{
		QStringList pluginList = settings.childGroups();
		foreach (QString pluginName, pluginList)
		{
			settings.beginGroup(pluginName);
			if (QSettings::NoError == settings.status())
			{
				bool load = settings.value("Load").toBool();
				if (load)
				{
					loadPlugin(pluginName, settings);
				}
				else
				{
					qInfo() << tr("Skipped loading plugin(%1). Load flag is false.").arg(pluginName);
				}
				settings.endGroup();
			}
			else
			{
				qWarning() << tr("Could not read plugin configuration(%1)").arg(pluginName);
			}
		}
	}
	else
	{
		qWarning() << "Could not read plugins configuration";
	}
}

void PluginManager::loadPlugin(const QString& pluginName, QSettings &settings)
{
	if (!mPluginMap.contains(pluginName))
	{
		emit loadingPlugin(pluginName);
		QCoreApplication::instance()->processEvents();

		QPluginLoader* loader = new QPluginLoader(pluginName);
		QObject* pluginInstance = loader->instance();
		Plugin* plugin = qobject_cast<Plugin*>(pluginInstance);
		
		if (0 != plugin)
		{
			qInfo() << QString("Plug-in loaded successfully(%1).").arg(pluginName).toLocal8Bit();

			mPluginMap.insert(pluginName, plugin);
		}
		else
		{
			qWarning() << QString("Plugin not loaded(%1). %2)").arg(pluginName).arg(loader->errorString()).toLocal8Bit();

			delete loader;
		}
	}
}