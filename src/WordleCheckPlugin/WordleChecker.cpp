#include <WordleCheckPlugin/WordleChecker.h>

#include <CoreApplication/CoreApplication.h>

#include <QtQml/QQmlContext>

#include <QtCore/QSettings>

WordleChecker::WordleChecker(QObject* parent)
	: mSecretWord("")
{
}

WordleChecker::~WordleChecker()
{
}

void WordleChecker::initialize()
{
	CoreApplication::registerSlot(
		"BeforeQmlContextCreatedEvent",
		this,
		SLOT(onBeforeQmlContextCreated(QQmlContext*)));

	QSettings settings;
	settings.beginGroup("WordleCase");

	if (QSettings::NoError == settings.status())
	{
		QStringList list = settings.childKeys();
		foreach(QString optionName, list)
		{
			if (optionName == QString("SecretWord"))
			{
				mSecretWord = settings.value(optionName).toString();
			}
		}
	}
}

QString WordleChecker::compare(QString word)
{
	//0 - default, 1 - yellow, 2 - green
	QString tempStr = mSecretWord;

	const int length = word.length();
	bool allTrue = true;

	for (int i = 0; i < length; i++)
	{
		if (mSecretWord.at(i) == word.at(i))
		{
			tempStr.replace(i, 1, '2');
			word.replace(i, 1, '2');
		}
		else
		{
			allTrue = false;
		}
	}

	if (!allTrue)
	{
		for (int i = 0; i < length; i++)
		{
			const QChar ch = word.at(i);

			if (ch != '2')
			{
				const int foundIndex = tempStr.indexOf(ch);

				if (-1 != foundIndex)
				{
					tempStr.replace(foundIndex, 1, '1');
					word.replace(i, 1, '1');
				}
				else
				{
					word.replace(i, 1, '0');
				}
			}
		}
	}

	return word;
}

void WordleChecker::onBeforeQmlContextCreated(QQmlContext* context)
{
	if (0 != context)
	{
		context->setContextProperty("WordleChecker", this);
	}
}