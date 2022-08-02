///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 18:06)

#ifndef BACKGROUND_SERVER_CORE_LIB_H
#define BACKGROUND_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BACKGROUND_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BackgroundServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BackgroundServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BACKGROUND_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BackgroundServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BackgroundServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BACKGROUND_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BACKGROUND_SERVER_CORE_LIB_H
