/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef RECHARGE_SERVER_CORE_LIB_H
#define RECHARGE_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

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