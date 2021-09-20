///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/29 22:11)

#ifndef BOOK_WINDOWS_API_LIB_H
#define BOOK_WINDOWS_API_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_WINDOWS_API_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookWindowsAPID.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookWindowsAPI.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_WINDOWS_API_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookWindowsAPIStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookWindowsAPIStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_WINDOWS_API_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_WINDOWS_API_LIB_H
