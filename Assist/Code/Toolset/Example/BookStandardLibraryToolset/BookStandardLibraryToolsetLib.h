///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 20:45)

#ifndef BOOK_STANDARD_LIBRARY_TOOLSET_LIB_H
#define BOOK_STANDARD_LIBRARY_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookStandardLibraryToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookStandardLibraryToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookStandardLibraryToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookStandardLibraryToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_STANDARD_LIBRARY_TOOLSET_LIB_H
