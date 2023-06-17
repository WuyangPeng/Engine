///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:33)

#ifndef LEVEL_EDITOR_LIB_H
#define LEVEL_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LEVEL_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LevelEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LevelEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LEVEL_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LevelEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LevelEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LEVEL_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LEVEL_EDITOR_LIB_H
