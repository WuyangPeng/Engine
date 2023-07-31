///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:13)

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
