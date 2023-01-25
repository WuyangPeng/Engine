///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/07 22:49)

#include "WinSockServentTesting.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSockServentTesting::WinSockServentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockServentTesting)

void System::WinSockServentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WinSockServentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetServentTest);
}

void System::WinSockServentTesting::GetServentTest()
{
    const auto* winSockServent0 = GetServentByPort(GetHostToNetShort(80), nullptr);
    WinSockServentTest(winSockServent0);

    const auto* winSockServent1 = GetServentByName("http", nullptr);
    WinSockServentTest(winSockServent1);
}

void System::WinSockServentTesting::WinSockServentTest(const WinSockServent* winSockServent)
{
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockServent, "获取的WinSockServent为空。");

    ASSERT_UNEQUAL_NULL_PTR(winSockServent->s_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent->s_aliases);
    ASSERT_EQUAL(winSockServent->s_port, GetHostToNetShort(80));
    ASSERT_UNEQUAL_NULL_PTR(winSockServent->s_proto);
}
