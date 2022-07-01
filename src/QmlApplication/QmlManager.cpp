#include <QmlApplication/QmlManager.h>

#include <CoreApplication/CoreApplication.h>

#include <QtCore/QSettings>

#include <QtQml/QQmlContext>
#include <QtQml/QQmlApplicationEngine>

#include <QtGui/QFontDatabase>
#include <QtGui/QGuiApplication>

QmlManager::QmlManager()
{
	CoreApplication::registerSignal(
		"QmlContextCreatedEvent",
		this,
		SIGNAL(emitQmlContextCreated(QQmlContext*)));

	CoreApplication::registerSignal(
		"BeforeQmlContextCreatedEvent",
		this,
		SIGNAL(beforeQmlContextCreated(QQmlContext*)));
}

void QmlManager::initialize()
{
}

void QmlManager::finalize()
{
}

void QmlManager::endInitialize()
{
	mEngine = new QQmlApplicationEngine();
	connect(mEngine,
		&QQmlApplicationEngine::objectCreated,
		this,
		&QmlManager::objectCreated);

	QSettings settings;
	settings.beginGroup("QmlManager");
	QString urlText = settings.value("Url").toString();
	qint32 size = settings.beginReadArray("ImportPathList");
	for (qint32 i = 0; i < size; ++i)
	{
		QString tag = "ImportPath";
		tag.append(QString::number(i + 1));
		QString importPath = settings.value(tag).toString();
		mEngine->addImportPath(importPath);
	}

	if (!urlText.isEmpty())
	{
		loadContext(urlText);
	}
}

QQmlContext* QmlManager::getCurrentContext()
{
	QQmlContext* qmlContext = 0;

	if (0 != mEngine)
	{
		qmlContext = mEngine->rootContext();
	}
	return qmlContext;
}

void QmlManager::loadContext(const QString& urlText)
{
	QQmlContext* qmlContext = mEngine->rootContext();

	emit beforeQmlContextCreated(qmlContext);

	mEngine->load(QUrl(urlText));

	emit emitQmlContextCreated(qmlContext);
}

void QmlManager::objectCreated(QObject* object, const QUrl& url)
{
	if (0 == object)
	{
		QString errorContent =
			"import QtQuick 2.12\n"
			"import QtQuick.Window 2.1\n"
			"\n"
			"Window {\n"
			"	width: 300\n"
			"	height : 400\n"
			"	visible: true\n"
			"\n"
			"	Text {\n"
			"		id: element\n"
			"		text : qsTr(\"ERROR: Could not load qml resources.\")\n"
			"		anchors.fill : parent\n"
			"		font.pixelSize : 14\n"
			"	}\n"
			"}\n";

		mEngine->loadData(errorContent.toLatin1());
	}
}