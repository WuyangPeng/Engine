///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/19 21:25)

#ifndef BOOK_CPP_LIB_H
#define BOOK_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_CPP_LIB_H
