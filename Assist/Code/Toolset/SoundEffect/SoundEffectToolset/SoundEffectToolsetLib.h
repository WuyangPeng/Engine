///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:25)

#ifndef SOUND_EFFECT_TOOLSET_LIB_H
#define SOUND_EFFECT_TOOLSET_LIB_H

#include "SoundEffect/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SOUND_EFFECT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffectToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SOUND_EFFECT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffectToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SOUND_EFFECT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SOUND_EFFECT_TOOLSET_LIB_H
