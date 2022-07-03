#include <WordleCheckPlugin/WordleChecker.h>

#include <CoreApplication/CoreApplication.h>

#include <QtQml/QQmlContext>

WordleChecker::WordleChecker(QObject* parent)
	: mSecretWord("ASDFG")
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
}

QString WordleChecker::compare(QString word)
{
	//0 - default, 1 - yellow, 2 - green
	//başta direkt yerinde var mı diye bak ilk arraydan o stringi sil ya da yerine saçma bir şey yaz.

	QString result;

	for (int i = 0; i < word.length(); i++)
	{
		const QChar ch = word.at(i);

		if (mSecretWord.contains(ch))
		{ 
			if (ch == mSecretWord.at(i))
			{
				result.append('2');
			}
			else
			{
				result.append('1');
			}
		}
		else
		{
			result.append('0');
		}
	}

	return result;
}

void WordleChecker::onBeforeQmlContextCreated(QQmlContext* context)
{
	if (0 != context)
	{
		context->setContextProperty("WordleChecker", this);
	}
}
