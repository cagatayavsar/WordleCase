#include <CoreApplication/Plugin.h>

#include <QtCore/QString>

Plugin::~Plugin()
{
}

void Plugin::beginInitialize()
{

}

void Plugin::endInitialize()
{
}

void Plugin::languageChanged()
{
}

QString Plugin::getVersion() const
{
	return QString();
}
