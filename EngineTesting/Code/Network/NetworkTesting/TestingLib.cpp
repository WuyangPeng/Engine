///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:35)

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
