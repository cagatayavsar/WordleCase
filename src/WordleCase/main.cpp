#include <QmlApplication/QmlApplication.h>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QmlApplication csQmlApp;
	csQmlApp.initialize();

	return csQmlApp.execute();
}