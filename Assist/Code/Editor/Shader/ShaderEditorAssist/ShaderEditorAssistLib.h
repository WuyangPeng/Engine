///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:42)

#ifndef SHADER_EDITOR_LIB_H
#define SHADER_EDITOR_LIB_H

#include "Helper/UserMacro.h"

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
