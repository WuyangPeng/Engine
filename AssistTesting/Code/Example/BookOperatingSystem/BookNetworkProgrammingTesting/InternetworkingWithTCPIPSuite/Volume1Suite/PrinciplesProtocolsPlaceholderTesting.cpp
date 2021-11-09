///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/23 22:11)

#include "PrinciplesProtocolsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/PrinciplesProtocolsAndArchitectures/Helper/PrinciplesProtocolsAndArchitecturesClassInvariantMacro.h"

BookNetworkProgramming::PrinciplesProtocolsAndArchitectures::PrinciplesProtocolsPlaceholderTesting::PrinciplesProtocolsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::PrinciplesProtocolsAndArchitectures, PrinciplesProtocolsPlaceholderTesting)

void BookNetworkProgramming::PrinciplesProtocolsAndArchitectures::PrinciplesProtocolsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::PrinciplesProtocolsAndArchitectures::PrinciplesProtocolsPlaceholderTesting::MainTest() noexcept
{
}
