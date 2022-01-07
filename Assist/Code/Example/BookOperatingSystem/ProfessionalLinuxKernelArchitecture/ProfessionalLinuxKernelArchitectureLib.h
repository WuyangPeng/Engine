///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:58)

#ifndef PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_LIB_H
#define PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalLinuxKernelArchitectureD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalLinuxKernelArchitecture.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalLinuxKernelArchitectureStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalLinuxKernelArchitectureStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROFESSIONAL_LINUX_KERNEL_ARCHITECTURE_LIB_H
