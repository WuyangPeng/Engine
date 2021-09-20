///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/23 20:49)

#ifndef THINKING_IN_CPP_VOLUME_TWO_LIB_H
#define THINKING_IN_CPP_VOLUME_TWO_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeTwoD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeTwo.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeTwoStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeTwoStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THINKING_IN_CPP_VOLUME_TWO_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THINKING_IN_CPP_VOLUME_TWO_LIB_H
