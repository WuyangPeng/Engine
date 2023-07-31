///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:47)

#ifndef ANIMATION_EDITOR_LIB_H
#define ANIMATION_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_EDITOR_LIB_H
