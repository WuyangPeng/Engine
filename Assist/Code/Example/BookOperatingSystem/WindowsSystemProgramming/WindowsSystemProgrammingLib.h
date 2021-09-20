///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/12 16:54)

#ifndef WINDOWS_SYSTEM_PROGRAMMING_LIB_H
#define WINDOWS_SYSTEM_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "WindowsSystemProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "WindowsSystemProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "WindowsSystemProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "WindowsSystemProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // WINDOWS_SYSTEM_PROGRAMMING_LIB_H
