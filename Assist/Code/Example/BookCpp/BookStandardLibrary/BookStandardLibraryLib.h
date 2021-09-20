///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/25 20:44)

#ifndef BOOK_STANDARD_LIBRARY_LIB_H
#define BOOK_STANDARD_LIBRARY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_STANDARD_LIBRARY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookStandardLibraryD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookStandardLibrary.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_STANDARD_LIBRARY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookStandardLibraryStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookStandardLibraryStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_STANDARD_LIBRARY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_STANDARD_LIBRARY_LIB_H
