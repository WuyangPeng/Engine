///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 14:50)

#ifndef SHADOW_EDITOR_LIB_H
#define SHADOW_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SHADOW_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ShadowEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ShadowEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SHADOW_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ShadowEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ShadowEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SHADOW_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SHADOW_EDITOR_LIB_H
