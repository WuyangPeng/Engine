///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:22)

#ifndef THE_DEVELOPERS_GUIDE_TO_DEBUGGING_LIB_H
#define THE_DEVELOPERS_GUIDE_TO_DEBUGGING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheDevelopersGuideToDebuggingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheDevelopersGuideToDebugging.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TheDevelopersGuideToDebuggingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheDevelopersGuideToDebuggingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_DEVELOPERS_GUIDE_TO_DEBUGGING_LIB_H
