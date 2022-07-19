///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 18:19)

#ifndef SCENE_LIB_H
#define SCENE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCENE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "SceneD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Scene.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SCENE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "SceneStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SceneStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SCENE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCENE_LIB_H
