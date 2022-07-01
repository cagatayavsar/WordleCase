#ifndef CoreApplication_GLOBAL_H
#define CoreApplication_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtCore/qobjectdefs.h>

#ifdef CoreApplication_LIB
# define COREAPPLICATION_EXPORT Q_DECL_EXPORT
#else
# define COREAPPLICATION_EXPORT Q_DECL_IMPORT
#endif

#endif // ACMI_GLOBAL_H
