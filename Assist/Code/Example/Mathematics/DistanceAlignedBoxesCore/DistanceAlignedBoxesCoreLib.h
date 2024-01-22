/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 16:33)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_LIB_H
#define DISTANCE_ALIGNED_BOXES_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DistanceAlignedBoxesCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DistanceAlignedBoxesCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DistanceAlignedBoxesCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DistanceAlignedBoxesCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DISTANCE_ALIGNED_BOXES_CORE_LIB_H
