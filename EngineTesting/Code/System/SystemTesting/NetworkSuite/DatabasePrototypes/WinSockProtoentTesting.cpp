///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/07 22:46)

#include "WinSockProtoentTesting.h"
#include "System/Network/DatabasePrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSockProtoentTesting::WinSockProtoentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockProtoentTesting)

void System::WinSockProtoentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WinSockProtoentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetProtoentTest);
}

void System::WinSockProtoentTesting::GetProtoentTest()
{
    const auto winSockProtoent0 = GetProtoentByNumber(1);
    ASSERT_NOT_THROW_EXCEPTION_1(WinSockProtoentTest, winSockProtoent0);

    const auto winSockProtoent1 = GetProtoentByName("tcp");
    ASSERT_NOT_THROW_EXCEPTION_1(WinSockProtoentTest, winSockProtoent1);
}

void System::WinSockProtoentTesting::WinSockProtoentTest(const WinSockProtoent* winSockProtoent)
{
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockProtoent, "获取的WinSockProtoent为空。");

    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent->p_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent->p_aliases);
    ASSERT_UNEQUAL(winSockProtoent->p_proto, 0);
}
