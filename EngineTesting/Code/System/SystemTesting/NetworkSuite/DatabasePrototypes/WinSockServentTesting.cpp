///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:42)

#include "WinSockServentTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/DatabasePrototypes.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

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
    auto winSockServent0 = GetServentByPort(GetHostToNetShort(80), nullptr);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent0);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent0->s_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent0->s_aliases);
    ASSERT_EQUAL(winSockServent0->s_port, GetHostToNetShort(80));
    ASSERT_UNEQUAL_NULL_PTR(winSockServent0->s_proto);

    auto winSockServent1 = GetServentByName("http", nullptr);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent1);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent1->s_name);
    ASSERT_UNEQUAL_NULL_PTR(winSockServent1->s_aliases);
    ASSERT_EQUAL(winSockServent1->s_port, GetHostToNetShort(80));
    ASSERT_UNEQUAL_NULL_PTR(winSockServent1->s_proto);
}
