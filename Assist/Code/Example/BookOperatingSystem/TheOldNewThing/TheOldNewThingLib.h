///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/19 23:07)

#ifndef THE_OLD_NEW_THING_LIB_H
#define THE_OLD_NEW_THING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_OLD_NEW_THING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheOldNewThingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheOldNewThing.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_OLD_NEW_THING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TheOldNewThingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheOldNewThingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_OLD_NEW_THING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_OLD_NEW_THING_LIB_H
