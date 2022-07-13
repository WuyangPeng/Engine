///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 11:17)

#ifndef FONT_EDITOR_LIB_H
#define FONT_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FONT_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "FontEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FontEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_FONT_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "FontEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FontEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_FONT_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FONT_EDITOR_LIB_H
