/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:21)

#ifndef SYSTEM_TOOLSET_LIB_H
#define SYSTEM_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SYSTEM_TOOLSET_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SystemToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SystemToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SYSTEM_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SystemToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SystemToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // !BUILDING_SYSTEM_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SYSTEM_TOOLSET_LIB_H
