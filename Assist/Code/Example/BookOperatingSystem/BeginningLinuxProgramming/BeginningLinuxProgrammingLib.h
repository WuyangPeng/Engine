///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:58)

#ifndef BEGINNING_LINUX_PROGRAMMING_LIB_H
#define BEGINNING_LINUX_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BeginningLinuxProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeginningLinuxProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BeginningLinuxProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BeginningLinuxProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BEGINNING_LINUX_PROGRAMMING_LIB_H
