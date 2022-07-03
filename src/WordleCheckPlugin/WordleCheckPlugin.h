#ifndef WordleCheckPlugin_WordleCheckPlugin
#define WordleCheckPlugin_WordleCheckPlugin

#include <QtCore/QObject>

#include <CoreApplication/Plugin.h>

class WordleChecker;

class WordleCheckPlugin
	: public QObject
	, Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "CoreApplication/Plugin")
	Q_INTERFACES(Plugin)

public:

	WordleCheckPlugin();

	virtual ~WordleCheckPlugin();

	virtual void initialize();

	virtual void finalize();

private:

	WordleChecker* mWordleChecker;
};

#endif