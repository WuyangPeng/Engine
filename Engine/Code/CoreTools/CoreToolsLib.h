/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 21:58)

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