///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:28)

#ifndef GATEWAY_SERVER_CORE_LIB_H
#define GATEWAY_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_GATEWAY_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "GatewayServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GatewayServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_GATEWAY_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "GatewayServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "GatewayServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_GATEWAY_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // GATEWAY_SERVER_CORE_LIB_H
