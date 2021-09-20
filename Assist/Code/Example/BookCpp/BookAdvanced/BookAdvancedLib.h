///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/09 22:11)

#ifndef BOOK_ADVANCED_LIB_H
#define BOOK_ADVANCED_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_ADVANCED_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookAdvancedD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAdvanced.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_ADVANCED_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookAdvancedStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAdvancedStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_ADVANCED_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_ADVANCED_LIB_H
