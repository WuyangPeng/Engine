///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:42)

#ifndef ANIMATION_TOOLSET_LIB_H
#define ANIMATION_TOOLSET_LIB_H

#include "Animation/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_TOOLSET_LIB_H