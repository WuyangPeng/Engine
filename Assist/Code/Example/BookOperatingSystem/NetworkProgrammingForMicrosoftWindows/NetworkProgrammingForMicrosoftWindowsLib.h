///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/01 21:08)

#ifndef NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_LIB_H
#define NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkProgrammingForMicrosoftWindowsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NetworkProgrammingForMicrosoftWindows.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "NetworkProgrammingForMicrosoftWindowsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NetworkProgrammingForMicrosoftWindowsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_LIB_H
