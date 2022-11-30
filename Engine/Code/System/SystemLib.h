///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:17)

#ifndef SYSTEM_LIB_H
#define SYSTEM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SYSTEM_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "SystemD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "System.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SYSTEM_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "SystemStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SystemStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SYSTEM_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SYSTEM_LIB_H