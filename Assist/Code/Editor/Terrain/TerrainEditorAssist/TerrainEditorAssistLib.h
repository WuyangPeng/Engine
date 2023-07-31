///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:25)

#ifndef TERRAIN_EDITOR_LIB_H
#define TERRAIN_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_TERRAIN_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "TerrainEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TerrainEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_TERRAIN_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "TerrainEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TerrainEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_TERRAIN_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // TERRAIN_EDITOR_LIB_H
