///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:08)

#ifndef ANIMATION_EXAMPLE_LIB_H
#define ANIMATION_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_EXAMPLE_LIB_H
