///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 14:33)

#ifndef SCENE_EDITOR_LIB_H
#define SCENE_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCENE_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "SceneEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SceneEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SCENE_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "SceneEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SceneEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SCENE_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCENE_EDITOR_LIB_H
