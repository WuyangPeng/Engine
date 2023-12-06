///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:47)

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
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockProtoEnt, "��ȡ��WinSockProtoentΪ�ա�");

    ASSERT_UNEQUAL_NULL_PTR(winSockProtoEnt->p_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockProtoEnt->p_aliases);
    ASSERT_UNEQUAL(winSockProtoEnt->p_proto, 0);
}
