///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "ConfiguringWindowsServerPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ConfiguringWindowsServer2008NetworkInfrastructure/Helper/ConfiguringWindowsServer2008NetworkInfrastructureClassInvariantMacro.h"

BookNetworkProgramming::ConfiguringWindowsServer2008NetworkInfrastructure::ConfiguringWindowsServerPlaceholderTesting::ConfiguringWindowsServerPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CONFIGURING_WINDOWS_SERVER_2008_NETWORK_INFRASTRUCTURE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::ConfiguringWindowsServer2008NetworkInfrastructure, ConfiguringWindowsServerPlaceholderTesting)

void BookNetworkProgramming::ConfiguringWindowsServer2008NetworkInfrastructure::ConfiguringWindowsServerPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::ConfiguringWindowsServer2008NetworkInfrastructure::ConfiguringWindowsServerPlaceholderTesting::MainTest() noexcept
{
}
