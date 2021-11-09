///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "MicrosoftWindowsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/NetworkProgrammingForMicrosoftWindows/Helper/NetworkProgrammingForMicrosoftWindowsClassInvariantMacro.h"

BookNetworkProgramming::NetworkProgrammingForMicrosoftWindows::MicrosoftWindowsPlaceholderTesting::MicrosoftWindowsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_PROGRAMMING_FOR_MICROSOFT_WINDOWS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::NetworkProgrammingForMicrosoftWindows, MicrosoftWindowsPlaceholderTesting)

void BookNetworkProgramming::NetworkProgrammingForMicrosoftWindows::MicrosoftWindowsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::NetworkProgrammingForMicrosoftWindows::MicrosoftWindowsPlaceholderTesting::MainTest() noexcept
{
}
