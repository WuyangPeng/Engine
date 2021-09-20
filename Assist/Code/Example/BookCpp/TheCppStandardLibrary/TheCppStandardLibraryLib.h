///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:44)

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
