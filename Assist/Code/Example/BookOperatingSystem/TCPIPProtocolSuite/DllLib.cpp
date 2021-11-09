///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/22 21:06)

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
