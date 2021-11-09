///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#ifndef CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_LIB_H
#define CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ConfiguringWindowsServer2008NetworkInfrastructureD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ConfiguringWindowsServer2008NetworkInfrastructure.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ConfiguringWindowsServer2008NetworkInfrastructureStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ConfiguringWindowsServer2008NetworkInfrastructureStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_LIB_H
