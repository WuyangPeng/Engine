///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 11:21)

#ifndef CORE_TOOLS_LIB_H
#define CORE_TOOLS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SYSTEM_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreTools.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SYSTEM_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreToolsStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SYSTEM_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_LIB_H