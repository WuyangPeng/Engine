///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:17)

#ifndef SCENE_OBJECT_LIB_H
#define SCENE_OBJECT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCENE_OBJECT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SceneObjectD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SceneObject.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SCENE_OBJECT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SceneObjectStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SceneObjectStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SCENE_OBJECT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCENE_OBJECT_LIB_H
