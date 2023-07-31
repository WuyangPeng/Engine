///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:53)

#ifndef SCENE_EDITOR_LIB_H
#define SCENE_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCENE_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SceneEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SceneEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SCENE_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SceneEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SceneEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SCENE_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCENE_EDITOR_LIB_H
