///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/06 20:45)

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
