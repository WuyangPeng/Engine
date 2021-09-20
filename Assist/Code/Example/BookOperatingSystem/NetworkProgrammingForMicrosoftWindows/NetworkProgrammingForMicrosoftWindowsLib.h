///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/01 21:08)

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
