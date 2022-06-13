///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:41)

#include "WinSockProtoentTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
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
    auto winSockProtoent0 = GetProtoentByNumber(0);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent0);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent0->p_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent0->p_aliases);
    ASSERT_EQUAL(winSockProtoent0->p_proto, 0);

    auto winSockProtoent1 = GetProtoentByName("tcp");
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent1);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent1->p_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoent1->p_aliases);
    ASSERT_UNEQUAL(winSockProtoent1->p_proto, 0);
}
