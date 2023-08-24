/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_LIB_H
#define RECHARGE_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

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