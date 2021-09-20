///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/04 23:12)

#ifndef BOOK_PRIMARY_TOOLSET_LIB_H
#define BOOK_PRIMARY_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookPrimaryToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookPrimaryToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookPrimaryToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookPrimaryToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_PRIMARY_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_PRIMARY_TOOLSET_LIB_H
