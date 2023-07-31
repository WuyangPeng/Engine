///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:54)

#ifndef SOUND_EFFECT_EXAMPLE_LIB_H
#define SOUND_EFFECT_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffectExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SoundEffectExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SoundEffectExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SOUND_EFFECT_EXAMPLE_LIB_H
