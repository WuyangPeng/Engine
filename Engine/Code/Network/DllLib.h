/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:54)

#ifndef NETWORK_DLL_LIB_H
#define NETWORK_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef NETWORK_USE_PROTO_BUF

        #ifdef _DEBUG

            #pragma comment(lib, "libprotobufd.lib")
            #pragma comment(lib, "libprotobuf-lited.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "libprotobuf.lib")
            #pragma comment(lib, "libprotobuf-lite.lib")

        #endif  // _DEBUG

    #endif  // NETWORK_USE_PROTO_BUF

    #ifdef NETWORK_USE_ACE

        #ifdef _DEBUG

            #pragma comment(lib, "ACEd.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ACE.lib")

        #endif  // _DEBUG

    #endif  // NETWORK_USE_ACE

    #ifdef NETWORK_USE_OPENSSL

        #pragma comment(lib, "libssl.lib")
        #pragma comment(lib, "libcrypto.lib")

    #endif  // NETWORK_USE_OPENSSL

    #ifdef NETWORK_USE_ACTIVE_MQ

        #ifdef _DEBUG

            #pragma comment(lib, "activemq-cppd.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "activemq-cpp.lib")

        #endif  // _DEBUG

    #endif  // NETWORK_USE_ACTIVE_MQ

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_DLL_LIB_H