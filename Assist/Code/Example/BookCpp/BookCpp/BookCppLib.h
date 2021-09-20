///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/19 21:25)

#ifndef BOOK_CPP_LIB_H
#define BOOK_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_CPP_LIB_H
