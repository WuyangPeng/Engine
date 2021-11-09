///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/24 22:21)

#include "TCPIPProtocolPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/TCPIPProtocolSuite/Helper/TCPIPProtocolSuiteClassInvariantMacro.h"

BookNetworkProgramming::TCPIPProtocol::TCPIPProtocolPlaceholderTesting::TCPIPProtocolPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    TCP_IP_PROTOCOL_SUITE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::TCPIPProtocol, TCPIPProtocolPlaceholderTesting)

void BookNetworkProgramming::TCPIPProtocol::TCPIPProtocolPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::TCPIPProtocol::TCPIPProtocolPlaceholderTesting::MainTest() noexcept
{
}
