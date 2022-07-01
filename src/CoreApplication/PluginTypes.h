#ifndef CoreApplication_PluginTypes
#define CoreApplication_PluginTypes

#include <CoreApplication/Plugin.h>

#include <QtCore/QHash>
#include <QtCore/QList>
#include <QtCore/QVector>

typedef QList<Plugin*> PluginList;
typedef QVector<Plugin*> PluginVector;
typedef QHash<QString, Plugin*> PluginHashMap;

#endif