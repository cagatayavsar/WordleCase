#ifndef WordleCheckPlugin_WordleChecker
#define WordleCheckPlugin_WordleChecker

#include <QtCore/QObject>

class QQmlContext;

class WordleChecker
	: public QObject
{
	Q_OBJECT

public:

	WordleChecker(QObject* parent = 0);

	~WordleChecker();

	void initialize();

	Q_INVOKABLE QString compare(QString word);

public slots:

	void onBeforeQmlContextCreated(QQmlContext* context);

private:

	QString mSecretWord;
};

#endif