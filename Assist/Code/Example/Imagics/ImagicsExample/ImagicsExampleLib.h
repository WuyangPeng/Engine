///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:41)

#ifndef IMAGICS_EXAMPLE_LIB_H
#define IMAGICS_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

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
