#ifndef CoreApplication_Plugin
#define CoreApplication_Plugin

#include <QtCore/QObject>
#include <CoreApplication/CoreApplication_global.h>

class COREAPPLICATION_EXPORT Plugin
{
public:

	virtual ~Plugin();

	virtual void beginInitialize();

	virtual void initialize() = 0;

	virtual void endInitialize();

	virtual void finalize() = 0;

	virtual void languageChanged();

	virtual QString getVersion() const;
};

Q_DECLARE_INTERFACE(Plugin, "CoreApplication/Plugin")

#endif