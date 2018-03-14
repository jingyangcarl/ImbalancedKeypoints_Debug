#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MESHSUBDIVISOR_LIB)
#  define MESHSUBDIVISOR_EXPORT Q_DECL_EXPORT
# else
#  define MESHSUBDIVISOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define MESHSUBDIVISOR_EXPORT
#endif
