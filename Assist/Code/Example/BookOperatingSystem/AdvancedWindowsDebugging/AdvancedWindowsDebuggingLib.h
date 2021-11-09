///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef ADVANCED_WINDOWS_DEBUGGING_LIB_H
#define ADVANCED_WINDOWS_DEBUGGING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedWindowsDebuggingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedWindowsDebugging.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedWindowsDebuggingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedWindowsDebuggingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ADVANCED_WINDOWS_DEBUGGING_LIB_H
