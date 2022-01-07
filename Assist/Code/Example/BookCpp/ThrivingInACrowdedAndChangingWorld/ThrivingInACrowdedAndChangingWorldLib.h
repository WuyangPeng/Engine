///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/30 21:53)

#ifndef THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_LIB_H
#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ThrivingInACrowdedAndChangingWorldD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThrivingInACrowdedAndChangingWorld.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ThrivingInACrowdedAndChangingWorldStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThrivingInACrowdedAndChangingWorldStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_LIB_H
