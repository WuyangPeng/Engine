///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 13:56)

#ifndef IMAGICS_EXAMPLE_LIB_H
#define IMAGICS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ImagicsExampleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ImagicsExample.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_IMAGICS_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ImagicsExampleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ImagicsExampleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_IMAGICS_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IMAGICS_EXAMPLE_LIB_H
