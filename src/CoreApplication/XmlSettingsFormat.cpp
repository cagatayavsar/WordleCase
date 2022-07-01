#include <CoreApplication/XmlSettingsFormat.h>

#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QXmlStreamReader>

bool XmlSettingsFormat::readXml(QIODevice & device, QSettings::SettingsMap & map)
{
	QFile* file = dynamic_cast<QFile*>(&device);
	
	QString path;
	if (0 != file)
	{
		path = file->fileName();
	}

	qInfo() << "Reading config file:\n" << path;

	QXmlStreamReader reader(&device);
	QStringList elements;

	while (!reader.atEnd() && !reader.hasError())
	{
		reader.readNext();
		QString name = reader.name().toString();

		if (reader.isStartElement() && name != "Settings")
		{
			elements.append(name);
		}
		else if (reader.isEndElement())
		{
			if (!elements.isEmpty())
			{
				elements.removeLast();
			}
		}
		else if (reader.isCharacters() && !reader.isWhitespace())
		{
			QString key;
			for (qint32 i = 0; i < elements.size(); i++)
			{
				if (i != 0)
				{
					key += "/";
				}
				key += elements.at(i);
			}

			if (reader.isCDATA())
			{
				QByteArray byteArray = QByteArray(reader.text().toLocal8Bit());
				map[key] = QByteArray::fromHex(byteArray);
			}
			else
			{
				QString value = reader.text().toString();
				map[key] = value;
			}
		}
	}

	bool result = true;
	if (reader.hasError())
	{
		qWarning() << reader.errorString();
		result = false;
	}

	return result;
}

bool XmlSettingsFormat::writeXml(QIODevice & device, const QSettings::SettingsMap & map)
{
	return false;
}

XmlSettingsFormat::XmlSettingsFormat()
{

}
