///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 19:33)

#ifndef BOOK_DEBUGGING_TOOLSET_LIB_H
#define BOOK_DEBUGGING_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookDebuggingToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookDebuggingToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookDebuggingToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookDebuggingToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_DEBUGGING_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_DEBUGGING_TOOLSET_LIB_H
