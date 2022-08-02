///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/27 22:12)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_LIB_H
#define RECHARGE_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RechargeServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RechargeServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RechargeServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RechargeServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_RECHARGE_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RECHARGE_SERVER_MIDDLE_LAYER_LIB_H
