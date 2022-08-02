///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:44)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_LIB_H
#define GATEWAY_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GatewayServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GatewayServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "GatewayServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GatewayServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GATEWAY_SERVER_MIDDLE_LAYER_LIB_H
