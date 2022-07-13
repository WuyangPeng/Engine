///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 16:01)

#ifndef ANIMATION_EXAMPLE_LIB_H
#define ANIMATION_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationExampleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AnimationExample.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AnimationExampleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AnimationExampleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_EXAMPLE_LIB_H
