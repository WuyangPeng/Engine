///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 23:42)

#ifndef BOOK_TEMPLATE_LIB_H
#define BOOK_TEMPLATE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_TEMPLATE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookTemplateD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookTemplate.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_TEMPLATE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookTemplateStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookTemplateStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_TEMPLATE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_TEMPLATE_LIB_H
