#pragma once

/******************** MeshSubdivisor.cpp ********************/
#define ALGORITHM_VERSION_4
#define POINT_POSITION_REMAIN
#define GET_NEIGHBOR_FUNCTION
//#define DEBUG

#if defined(ALGORITHM_VERSION_1)
#define VERSION_1
#elif defined(ALGORITHM_VERSION_2)
#define VERSION_2
#elif defined(ALGORITHM_VERSION_3)
#define VERSION_3
#elif defined(ALGORITHM_VERSION_4)
#define VERSION_4
#endif

#if defined(POINT_POSITION_REMAIN)
#define POINT_VERSION_1
#elif defined(POINT_POSITION_ADJUST)
#define POINT_VERSION_2
#endif

#if defined(GET_NEIGHBOR_LINE)
#define GET_NEIGHBOR_VERSION_1
#elif defined(GET_NEIGHBOR_FUNCTION)
#define GET_NEIGHBOR_VERSION_2
#endif