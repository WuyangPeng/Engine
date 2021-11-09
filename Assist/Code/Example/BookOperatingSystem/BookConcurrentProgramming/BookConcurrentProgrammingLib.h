///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/26 23:05)

#ifndef BOOK_CONCURRENT_PROGRAMMING_LIB_H
#define BOOK_CONCURRENT_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookConcurrentProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookConcurrentProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookConcurrentProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookConcurrentProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_CONCURRENT_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_CONCURRENT_PROGRAMMING_LIB_H
