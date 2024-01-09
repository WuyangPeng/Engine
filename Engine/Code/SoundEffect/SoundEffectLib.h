/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 20:05)

#ifndef SOUND_EFFECT_LIB_H
#define SOUND_EFFECT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SOUND_EFFECT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffect.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SOUND_EFFECT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffectStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SOUND_EFFECT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SOUND_EFFECT_LIB_H