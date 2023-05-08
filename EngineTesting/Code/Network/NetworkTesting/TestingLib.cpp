///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 16:35)

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Network/NetworkLib.h"

#ifdef NETWORK_USE_ACE

    #ifdef _DEBUG

        #pragma comment(lib, "ACEd.lib")

    #else  // !_DEBUG

        #pragma comment(lib, "ACE.lib")

    #endif  // _DEBUG

#endif  // NETWORK_USE_ACE

#ifdef NETWORK_USE_PROTO_BUF

    #ifdef _DEBUG

        #pragma comment(lib, "libprotobufd.lib")
        #pragma comment(lib, "libprotobuf-lited.lib")

    #else  // !_DEBUG

        #pragma comment(lib, "libprotobuf.lib")
        #pragma comment(lib, "libprotobuf-lite.lib")

    #endif  // _DEBUG

#endif  // NETWORK_USE_PROTO_BUF
