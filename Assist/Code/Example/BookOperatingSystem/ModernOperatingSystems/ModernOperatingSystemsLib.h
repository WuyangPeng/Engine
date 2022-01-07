///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/06 21:21)

#ifndef MODERN_OPERATING_SYSTEMS_LIB_H
#define MODERN_OPERATING_SYSTEMS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ModernOperatingSystemsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ModernOperatingSystems.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ModernOperatingSystemsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ModernOperatingSystemsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MODERN_OPERATING_SYSTEMS_LIB_H
