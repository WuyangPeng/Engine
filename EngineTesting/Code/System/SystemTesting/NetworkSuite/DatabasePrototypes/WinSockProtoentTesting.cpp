///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 14:22)

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
