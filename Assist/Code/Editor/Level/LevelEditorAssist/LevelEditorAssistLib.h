///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/07 16:20)

#ifndef LEVEL_EDITOR_LIB_H
#define LEVEL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LEVEL_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "LevelEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LevelEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_LEVEL_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "LevelEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LevelEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_LEVEL_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LEVEL_EDITOR_LIB_H
