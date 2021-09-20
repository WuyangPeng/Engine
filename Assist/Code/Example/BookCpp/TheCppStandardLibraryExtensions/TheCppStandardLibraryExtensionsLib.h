///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef THE_CPP_STANDARD_LIBRARY_EXTENSIONS_LIB_H
#define THE_CPP_STANDARD_LIBRARY_EXTENSIONS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppStandardLibraryExtensionsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppStandardLibraryExtensions.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppStandardLibraryExtensionsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppStandardLibraryExtensionsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_CPP_STANDARD_LIBRARY_EXTENSIONS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_CPP_STANDARD_LIBRARY_EXTENSIONS_LIB_H
