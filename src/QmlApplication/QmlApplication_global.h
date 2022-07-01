#ifndef QmlApplication_GLOBAL_H
#define QmlApplication_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore/qobjectdefs.h>

#ifdef QMLAPPLICATION_LIB
# define QMLAPPLICATION_EXPORT Q_DECL_EXPORT
#else
# define QMLAPPLICATION_EXPORT Q_DECL_IMPORT
#endif


#endif