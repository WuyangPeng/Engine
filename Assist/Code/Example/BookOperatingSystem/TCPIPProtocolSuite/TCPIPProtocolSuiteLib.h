///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:06)

#ifndef TCP_IP_PROTOCOL_SUITE_LIB_H
#define TCP_IP_PROTOCOL_SUITE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TCPIPProtocolSuiteD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TCPIPProtocolSuite.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TCPIPProtocolSuiteStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TCPIPProtocolSuiteStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // TCP_IP_PROTOCOL_SUITE_LIB_H
