///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/29 22:11)

#ifndef BOOK_ACE_LIB_H
#define BOOK_ACE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_ACE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookACED.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookACE.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_ACE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookACEStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookACEStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_ACE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_ACE_LIB_H
