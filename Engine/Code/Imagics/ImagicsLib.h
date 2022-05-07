///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 16:44)

#ifndef IMAGICS_LIB_H
#define IMAGICS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IMAGICS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ImagicsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Imagics.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_IMAGICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ImagicsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ImagicsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_IMAGICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IMAGICS_LIB_H