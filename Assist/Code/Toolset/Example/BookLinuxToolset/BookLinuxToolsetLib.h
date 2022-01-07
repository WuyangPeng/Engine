///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/24 20:51)

#ifndef BOOK_LINUX_TOOLSET_LIB_H
#define BOOK_LINUX_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_LINUX_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookLinuxToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookLinuxToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_LINUX_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookLinuxToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookLinuxToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_LINUX_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_LINUX_TOOLSET_LIB_H
