///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 17:46)

#ifndef SHADER_EDITOR_LIB_H
#define SHADER_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SHADER_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ShaderEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ShaderEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SHADER_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ShaderEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ShaderEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SHADER_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SHADER_EDITOR_LIB_H
