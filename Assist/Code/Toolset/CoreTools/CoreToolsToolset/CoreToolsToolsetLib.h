/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:40)

#ifndef CORE_TOOLS_TOOLSET_LIB_H
#define CORE_TOOLS_TOOLSET_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORE_TOOLS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreToolsToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CORE_TOOLS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreToolsToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CORE_TOOLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_TOOLSET_LIB_H
