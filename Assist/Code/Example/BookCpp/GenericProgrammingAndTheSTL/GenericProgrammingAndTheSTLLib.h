///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:44)

#ifndef GENERIC_PROGRAMMING_AND_THE_STL_LIB_H
#define GENERIC_PROGRAMMING_AND_THE_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GenericProgrammingAndTheSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GenericProgrammingAndTheSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "GenericProgrammingAndTheSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GenericProgrammingAndTheSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GENERIC_PROGRAMMING_AND_THE_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GENERIC_PROGRAMMING_AND_THE_STL_LIB_H
