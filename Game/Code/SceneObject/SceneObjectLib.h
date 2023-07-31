///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:16)

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
