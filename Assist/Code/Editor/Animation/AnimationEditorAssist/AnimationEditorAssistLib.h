///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 16:18)
///	���渨���汾��0.9.0.12 (2022/07/06 14:21)

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
