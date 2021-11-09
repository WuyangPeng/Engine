///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#ifndef PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H
#define PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H
