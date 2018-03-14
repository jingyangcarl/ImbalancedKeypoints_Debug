#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CELLULARAUTOMATON_LIB)
#  define CELLULARAUTOMATON_EXPORT Q_DECL_EXPORT
# else
#  define CELLULARAUTOMATON_EXPORT Q_DECL_IMPORT
# endif
#else
# define CELLULARAUTOMATON_EXPORT
#endif
