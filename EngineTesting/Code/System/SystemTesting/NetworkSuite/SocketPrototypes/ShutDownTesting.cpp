/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:14)

#include "ShutDownTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ShutDownTesting::ShutDownTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ShutDownTesting)

void System::ShutDownTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::ShutDownTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Receive);
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Send);
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Both);
}

void System::ShutDownTesting::ShutDownTest(ShutdownHow shutdownHow)
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_2(DoShutDownTest, socketHandle, shutdownHow);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::ShutDownTesting::DoShutDownTest(WinSocket socketHandle, ShutdownHow shutdownHow)
{
    const auto address = GetAddress(GetConnectPort(), GetConnectHostname());
    ASSERT_TRUE(Connect(socketHandle, &address));

    ASSERT_TRUE(ShutDown(socketHandle, shutdownHow));
}
