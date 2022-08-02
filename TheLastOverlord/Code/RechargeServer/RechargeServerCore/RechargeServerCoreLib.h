///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 22:08)

#ifndef RECHARGE_SERVER_CORE_LIB_H
#define RECHARGE_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RechargeServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RechargeServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_RECHARGE_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RechargeServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RechargeServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_RECHARGE_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RECHARGE_SERVER_CORE_LIB_H
