///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:17)

#ifndef ACTIVITY_LIB_H
#define ACTIVITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ACTIVITY_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ActivityD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Activity.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ACTIVITY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ActivityStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ActivityStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ACTIVITY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ACTIVITY_LIB_H
