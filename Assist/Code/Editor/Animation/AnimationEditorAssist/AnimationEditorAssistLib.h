///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/06 14:21)

#ifndef ANIMATION_EDITOR_LIB_H
#define ANIMATION_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AnimationEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AnimationEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_EDITOR_LIB_H
