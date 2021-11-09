///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 8:44)

#ifndef DESIGN_IMPLEMENTATION_AND_INTERNALS_LIB_H
#define DESIGN_IMPLEMENTATION_AND_INTERNALS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DesignImplementationAndInternalsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DesignImplementationAndInternals.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "DesignImplementationAndInternalsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DesignImplementationAndInternalsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DESIGN_IMPLEMENTATION_AND_INTERNALS_LIB_H
