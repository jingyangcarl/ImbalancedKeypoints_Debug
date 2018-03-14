#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MESHSURFACEFITTER_LIB)
#  define MESHSURFACEFITTER_EXPORT Q_DECL_EXPORT
# else
#  define MESHSURFACEFITTER_EXPORT Q_DECL_IMPORT
# endif
#else
# define MESHSURFACEFITTER_EXPORT
#endif
