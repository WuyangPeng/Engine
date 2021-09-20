///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/24 20:47)

#ifndef BOOK_OPERATING_SYSTEM_LIB_H
#define BOOK_OPERATING_SYSTEM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_OPERATING_SYSTEM_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookOperatingSystemD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookOperatingSystem.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_OPERATING_SYSTEM_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookOperatingSystemStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookOperatingSystemStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_OPERATING_SYSTEM_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_OPERATING_SYSTEM_LIB_H
