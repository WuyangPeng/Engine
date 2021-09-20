///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:44)

#ifndef CPP_STL_LIB_H
#define CPP_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_STL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_STL_LIB_H
