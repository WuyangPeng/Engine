///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:06)

#ifndef CRYPTOGRAPHY_AND_NETWORK_SECURITY_LIB_H
#define CRYPTOGRAPHY_AND_NETWORK_SECURITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CryptographyAndNetworkSecurityD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CryptographyAndNetworkSecurity.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CryptographyAndNetworkSecurityStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CryptographyAndNetworkSecurityStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CRYPTOGRAPHY_AND_NETWORK_SECURITY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CRYPTOGRAPHY_AND_NETWORK_SECURITY_LIB_H
