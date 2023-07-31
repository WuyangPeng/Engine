///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:21)

#ifndef EFFECT_EDITOR_LIB_H
#define EFFECT_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EFFECT_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "EffectEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "EffectEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_EFFECT_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "EffectEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "EffectEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_EFFECT_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EFFECT_EDITOR_LIB_H
