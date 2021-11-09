///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/24 21:42)

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
