///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/22 21:06)

#include "Example/BookOperatingSystem/TCPIPProtocolSuite/TCPIPProtocolSuiteExport.h"

#include "TCPIPProtocolSuite.h"

#ifndef BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC

namespace TCPIPProtocolSuite
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_TCP_IP_PROTOCOL_SUITE_STATIC
