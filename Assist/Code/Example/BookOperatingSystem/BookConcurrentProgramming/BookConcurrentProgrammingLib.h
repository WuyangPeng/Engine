///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/26 23:05)

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
