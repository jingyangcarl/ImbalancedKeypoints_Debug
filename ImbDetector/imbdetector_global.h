#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMBDETECTOR_LIB)
#  define IMBDETECTOR_EXPORT Q_DECL_EXPORT
# else
#  define IMBDETECTOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMBDETECTOR_EXPORT
#endif
