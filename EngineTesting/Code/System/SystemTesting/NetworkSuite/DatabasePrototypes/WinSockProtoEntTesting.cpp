///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:47)

#include "WinSockProtoEntTesting.h"
#include "System/Network/DatabasePrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSockProtoEntTesting::WinSockProtoEntTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockProtoEntTesting)

void System::WinSockProtoEntTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WinSockProtoEntTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetProtoEntTest);
}

void System::WinSockProtoEntTesting::GetProtoEntTest()
{
    const auto winSockProtoEnt0 = GetProtoByNumber(1);
    ASSERT_NOT_THROW_EXCEPTION_1(WinSockProtoEntTest, winSockProtoEnt0);

    const auto winSockProtoEnt1 = GetProtoByName("tcp");
    ASSERT_NOT_THROW_EXCEPTION_1(WinSockProtoEntTest, winSockProtoEnt1);
}

void System::WinSockProtoEntTesting::WinSockProtoEntTest(const WinSockProtoEnt* winSockProtoEnt)
{
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockProtoEnt, "获取的WinSockProtoent为空。");

    ASSERT_UNEQUAL_NULL_PTR(winSockProtoEnt->p_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoEnt->p_aliases);
    ASSERT_UNEQUAL(winSockProtoEnt->p_proto, 0);
}
