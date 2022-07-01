#ifndef CoreApplication_LogManager
#define CoreApplication_LogManager

#include <CoreApplication/Initializable.h>
#include <CoreApplication/CoreApplication_global.h>

#include <QtCore/QObject>

class COREAPPLICATION_EXPORT LogManager
	: public QObject
	, public Initializable
{

public:

	LogManager();

	virtual void initialize();

	virtual void finalize();

};

#endif