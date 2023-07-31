///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:47)

#ifndef ANIMATION_EDITOR_LIB_H
#define ANIMATION_EDITOR_LIB_H

#include "Helper/UserMacro.h"

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
