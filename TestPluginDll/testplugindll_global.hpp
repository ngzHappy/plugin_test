#ifndef TESTPLUGINDLL_GLOBAL_HPP
#define TESTPLUGINDLL_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(TESTPLUGINDLL_LIBRARY)
#  define TESTPLUGINDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TESTPLUGINDLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTPLUGINDLL_GLOBAL_HPP
