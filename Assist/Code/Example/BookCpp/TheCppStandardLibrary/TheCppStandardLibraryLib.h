///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:44)

#ifndef THE_CPP_STANDARD_LIBRARY_LIB_H
#define THE_CPP_STANDARD_LIBRARY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppStandardLibraryD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppStandardLibrary.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppStandardLibraryStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppStandardLibraryStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_CPP_STANDARD_LIBRARY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_CPP_STANDARD_LIBRARY_LIB_H
