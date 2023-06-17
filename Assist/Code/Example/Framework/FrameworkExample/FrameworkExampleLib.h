///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 14:56)

#ifndef FRAMEWORK_EXAMPLE_LIB_H
#define FRAMEWORK_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_FRAMEWORK_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_FRAMEWORK_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FRAMEWORK_EXAMPLE_LIB_H
