#ifndef CoreApplication_XmlSettingsFormat
#define CoreApplication_XmlSettingsFormat

#include <QtCore/QSettings>

class QIODevice;

class XmlSettingsFormat
{
public:

	static bool readXml(QIODevice& device, QSettings::SettingsMap& map);

	static bool writeXml(QIODevice& device, const QSettings::SettingsMap& map);

private:

	XmlSettingsFormat();
};

#endif