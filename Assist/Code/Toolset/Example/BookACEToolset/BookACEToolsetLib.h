///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/12 0:07)

#ifndef BOOK_ACE_TOOLSET_LIB_H
#define BOOK_ACE_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_ACE_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookACEToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookACEToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_ACE_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookACEToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookACEToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_ACE_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_ACE_TOOLSET_LIB_H
