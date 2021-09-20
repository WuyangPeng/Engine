///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef DATA_STRUCTURES_WITH_CPP_USING_STL_LIB_H
#define DATA_STRUCTURES_WITH_CPP_USING_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DataStructuresWithCppUsingSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataStructuresWithCppUsingSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "DataStructuresWithCppUsingSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataStructuresWithCppUsingSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DATA_STRUCTURES_WITH_CPP_USING_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATA_STRUCTURES_WITH_CPP_USING_STL_LIB_H
