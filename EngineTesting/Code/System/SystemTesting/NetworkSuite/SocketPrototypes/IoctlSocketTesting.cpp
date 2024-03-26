/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:13)

#include "IoctlSocketTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Using/WindowsSockExUsing.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::IoctlSocketTesting::IoctlSocketTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, IoctlSocketTesting)

void System::IoctlSocketTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::IoctlSocketTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IoctlSocketTest);
}

void System::IoctlSocketTesting::IoctlSocketTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoIoctlSocketTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::IoctlSocketTesting::DoIoctlSocketTest(WinSocket socketHandle)
{
    unsigned long argumentParser{ 0 };
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FIonBlockingIO, &argumentParser));

    argumentParser = 1;
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FIonBlockingIO, &argumentParser));

    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FIonRead, &argumentParser));
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::SocketIOControlsAtMark, &argumentParser));
}
