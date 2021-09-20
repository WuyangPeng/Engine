///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/23 22:41)

#ifndef BOOK_WINDOWS_API_TOOLSET_LIB_H
#define BOOK_WINDOWS_API_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookWindowsAPIToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookWindowsAPIToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookWindowsAPIToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookWindowsAPIToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_WINDOWS_API_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_WINDOWS_API_TOOLSET_LIB_H
