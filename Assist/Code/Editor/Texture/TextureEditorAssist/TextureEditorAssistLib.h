///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:20)

#ifndef TEXTURE_EDITOR_LIB_H
#define TEXTURE_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_TEXTURE_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "TextureEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TextureEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_TEXTURE_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "TextureEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TextureEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_TEXTURE_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // TEXTURE_EDITOR_LIB_H
