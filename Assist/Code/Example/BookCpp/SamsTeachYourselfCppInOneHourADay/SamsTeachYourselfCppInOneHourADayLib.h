///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/27 19:45)

#ifndef SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_LIB_H
#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "SamsTeachYourselfCppInOneHourADayD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SamsTeachYourselfCppInOneHourADay.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "SamsTeachYourselfCppInOneHourADayStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SamsTeachYourselfCppInOneHourADayStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_LIB_H
