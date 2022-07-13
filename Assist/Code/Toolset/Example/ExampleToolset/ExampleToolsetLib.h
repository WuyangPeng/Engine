///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 11:43)

#ifndef EXAMPLE_TOOLSET_LIB_H
#define EXAMPLE_TOOLSET_LIB_H

#include "Macro/Macro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ExampleToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExampleToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ExampleToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExampleToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EXAMPLE_TOOLSET_LIB_H
