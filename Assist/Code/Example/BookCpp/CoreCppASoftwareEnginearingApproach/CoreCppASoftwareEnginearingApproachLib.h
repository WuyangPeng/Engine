///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 13:05)

#ifndef CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_LIB_H
#define CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CoreCppASoftwareEnginearingApproachD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CoreCppASoftwareEnginearingApproach.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CoreCppASoftwareEnginearingApproachStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CoreCppASoftwareEnginearingApproachStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_LIB_H
