///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:42)

#ifndef ANIMATION_TOOLSET_LIB_H
#define ANIMATION_TOOLSET_LIB_H

#include "Animation/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ANIMATION_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ANIMATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "AnimationToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "AnimationToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ANIMATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ANIMATION_TOOLSET_LIB_H