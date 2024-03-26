/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:12)

#include "WinSockServerEntTesting.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSockServerEntTesting::WinSockServerEntTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSockServerEntTesting)

void System::WinSockServerEntTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WinSockServerEntTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetServerEntTest);
}

void System::WinSockServerEntTesting::GetServerEntTest()
{
    const auto* winSockServEnt0 = GetServerByPort(GetHostToNetShort(80), nullptr);
    WinSockServerEntTest(winSockServEnt0);

    const auto* winSockServEnt1 = GetServerByName("http", nullptr);
    WinSockServerEntTest(winSockServEnt1);
}

void System::WinSockServerEntTesting::WinSockServerEntTest(const WinSockServerEnt* winSockServEnt)
{
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(winSockServEnt, "��ȡ��WinSockServentΪ�ա�");

    ASSERT_UNEQUAL_NULL_PTR(winSockServEnt->s_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockServEnt->s_aliases);
    ASSERT_EQUAL(winSockServEnt->s_port, GetHostToNetShort(80));
    ASSERT_UNEQUAL_NULL_PTR(winSockServEnt->s_proto);
}
