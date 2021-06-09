#ifndef QPIPC_GLOBAL_H
#define QPIPC_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPIPC_LIBRARY)
#  define QPIPC_EXPORT Q_DECL_EXPORT
#else
#  define QPIPC_EXPORT Q_DECL_IMPORT
#endif

#endif // QPIPC_GLOBAL_H
