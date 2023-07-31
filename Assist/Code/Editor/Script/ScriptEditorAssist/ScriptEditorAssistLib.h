///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:50)

#ifndef SCRIPT_EDITOR_LIB_H
#define SCRIPT_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCRIPT_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ScriptEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SCRIPT_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ScriptEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SCRIPT_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_EDITOR_LIB_H
