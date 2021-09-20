///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/21 19:14)

#ifndef BOOK_BOOST_LIB_H
#define BOOK_BOOST_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_BOOST_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookBoostD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookBoost.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_BOOST_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookBoostStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookBoostStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_BOOST_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_BOOST_LIB_H
