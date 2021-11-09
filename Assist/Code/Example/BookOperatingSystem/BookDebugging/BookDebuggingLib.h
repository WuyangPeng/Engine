///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 21:34)

#ifndef BOOK_DEBUGGING_LIB_H
#define BOOK_DEBUGGING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_DEBUGGING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookDebuggingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookDebugging.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_DEBUGGING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookDebuggingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookDebuggingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_DEBUGGING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_DEBUGGING_LIB_H
