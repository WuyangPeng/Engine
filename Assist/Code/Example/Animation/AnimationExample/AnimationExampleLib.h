///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:08)

#ifndef ANIMATION_EXAMPLE_LIB_H
#define ANIMATION_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

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
