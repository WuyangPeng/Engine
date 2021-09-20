///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.0 (2021/07/18 11:25)

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