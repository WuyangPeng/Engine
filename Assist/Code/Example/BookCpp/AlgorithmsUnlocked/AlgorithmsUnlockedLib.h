///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef ALGORITHMS_UNLOCKED_LIB_H
#define ALGORITHMS_UNLOCKED_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMS_UNLOCKED_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsUnlockedD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsUnlocked.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMS_UNLOCKED_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsUnlockedStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsUnlockedStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMS_UNLOCKED_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMS_UNLOCKED_LIB_H
