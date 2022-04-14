///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/25 13:48)

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