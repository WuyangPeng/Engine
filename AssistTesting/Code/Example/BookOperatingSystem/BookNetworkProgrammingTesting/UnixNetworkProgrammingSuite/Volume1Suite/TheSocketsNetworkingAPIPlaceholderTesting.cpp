///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/24 21:42)

#include "TheSocketsNetworkingAPIPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/TheSocketsNetworkingAPI/Helper/TheSocketsNetworkingAPIClassInvariantMacro.h"

BookNetworkProgramming::UnixNetworkProgramming::TheSocketsNetworkingAPIPlaceholderTesting::TheSocketsNetworkingAPIPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_SOCKETS_NETWORKING_API_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookNetworkProgramming::UnixNetworkProgramming, TheSocketsNetworkingAPIPlaceholderTesting)

void BookNetworkProgramming::UnixNetworkProgramming::TheSocketsNetworkingAPIPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookNetworkProgramming::UnixNetworkProgramming::TheSocketsNetworkingAPIPlaceholderTesting::MainTest() noexcept
{
}
