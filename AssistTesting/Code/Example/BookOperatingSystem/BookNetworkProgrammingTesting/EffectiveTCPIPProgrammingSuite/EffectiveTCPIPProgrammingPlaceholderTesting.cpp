///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 22:11)

#include "EffectiveTCPIPProgrammingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/EffectiveTCPIPProgramming/Helper/EffectiveTCPIPProgrammingClassInvariantMacro.h"

BookNetworkProgramming::EffectiveTCPIPProgramming::EffectiveTCPIPProgrammingPlaceholderTesting::EffectiveTCPIPProgrammingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    EFFECTIVE_TCP_IP_PROGRAMMING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::EffectiveTCPIPProgramming, EffectiveTCPIPProgrammingPlaceholderTesting)

void BookNetworkProgramming::EffectiveTCPIPProgramming::EffectiveTCPIPProgrammingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::EffectiveTCPIPProgramming::EffectiveTCPIPProgrammingPlaceholderTesting::MainTest() noexcept
{
}
