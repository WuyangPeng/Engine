///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/17 19:23)

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