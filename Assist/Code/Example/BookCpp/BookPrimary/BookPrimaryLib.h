///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/21 20:51)

#ifndef BOOK_PRIMARY_LIB_H
#define BOOK_PRIMARY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_PRIMARY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookPrimaryD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookPrimary.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_PRIMARY_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BookPrimaryStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookPrimaryStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_PRIMARY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_PRIMARY_LIB_H
