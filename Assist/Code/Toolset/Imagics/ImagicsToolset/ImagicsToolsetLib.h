///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:44)

#ifndef IMAGICS_TOOLSET_LIB_H
#define IMAGICS_TOOLSET_LIB_H

#include "Imagics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IMAGICS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ImagicsToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ImagicsToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_IMAGICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ImagicsToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ImagicsToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_IMAGICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IMAGICS_TOOLSET_LIB_H
