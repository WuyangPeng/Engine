///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "ComputerNetworksPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ComputerNetworks/Helper/ComputerNetworksClassInvariantMacro.h"

BookNetworkProgramming::ComputerNetworks::ComputerNetworksPlaceholderTesting::ComputerNetworksPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    COMPUTER_NETWORKS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::ComputerNetworks, ComputerNetworksPlaceholderTesting)

void BookNetworkProgramming::ComputerNetworks::ComputerNetworksPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::ComputerNetworks::ComputerNetworksPlaceholderTesting::MainTest() noexcept
{
}
