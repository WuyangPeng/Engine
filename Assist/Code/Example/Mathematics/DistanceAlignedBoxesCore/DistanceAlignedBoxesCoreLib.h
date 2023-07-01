///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/20 11:01)

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
