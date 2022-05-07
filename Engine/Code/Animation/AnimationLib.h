///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/27 16:48)

#ifndef ANIMATION_LIB_H
#define ANIMATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Animation.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AnimationStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_LIB_H