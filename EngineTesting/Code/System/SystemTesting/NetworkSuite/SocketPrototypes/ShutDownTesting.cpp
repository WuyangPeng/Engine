///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/11 17:58)

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
    const auto address = GetAddress(defaultHttpPort, GetConnectHostname());
    ASSERT_TRUE(Connect(socketHandle, &address));

    ASSERT_TRUE(ShutDown(socketHandle, shutdownHow));
}
