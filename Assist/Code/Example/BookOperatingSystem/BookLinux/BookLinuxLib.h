///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 14:31)

#ifndef BOOK_LINUX_LIB_H
#define BOOK_LINUX_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_LINUX_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookLinuxD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookLinux.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_LINUX_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookLinuxStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookLinuxStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_LINUX_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_LINUX_LIB_H
