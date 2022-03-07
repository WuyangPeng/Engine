///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/15 13:25)

#ifndef NETWORK_DLL_LIB_H
#define NETWORK_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#if defined(TCRE_USE_MSVC)

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

#endif  // TCRE_USE_MSVC

#endif  // NETWORK_DLL_LIB_H