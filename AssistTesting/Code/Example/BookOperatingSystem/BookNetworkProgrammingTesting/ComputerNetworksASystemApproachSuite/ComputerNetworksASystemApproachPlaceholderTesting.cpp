///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/24 22:21)

#include "ComputerNetworksASystemApproachPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/ComputerNetworksASystemApproach/Helper/ComputerNetworksASystemApproachClassInvariantMacro.h"

BookNetworkProgramming::ComputerNetworksASystemApproach::ComputerNetworksASystemApproachPlaceholderTesting::ComputerNetworksASystemApproachPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    COMPUTER_NETWORKS_A_SYSTEM_APPROACH_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::ComputerNetworksASystemApproach, ComputerNetworksASystemApproachPlaceholderTesting)

void BookNetworkProgramming::ComputerNetworksASystemApproach::ComputerNetworksASystemApproachPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::ComputerNetworksASystemApproach::ComputerNetworksASystemApproachPlaceholderTesting::MainTest() noexcept
{
}
