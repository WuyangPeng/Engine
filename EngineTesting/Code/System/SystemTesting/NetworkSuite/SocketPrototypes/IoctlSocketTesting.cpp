///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/10 0:26)

#include "IoctlSocketTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
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
    unsigned long argp{ 0 };
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionBio, &argp));

    argp = 1;
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionBio, &argp));

    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionRead, &argp));
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::Siocatmark, &argp));
}
