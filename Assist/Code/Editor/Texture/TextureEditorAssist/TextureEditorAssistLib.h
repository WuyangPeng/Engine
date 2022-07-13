///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/11 13:48)

#ifndef TEXTURE_EDITOR_LIB_H
#define TEXTURE_EDITOR_LIB_H

#include "Macro/UserMacro.h"

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
