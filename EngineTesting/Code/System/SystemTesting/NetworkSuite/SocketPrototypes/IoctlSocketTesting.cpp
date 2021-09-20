///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 11:20)

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
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::IoctlSocketTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IoctlSocketTest);
}

void System::IoctlSocketTesting::IoctlSocketTest()
{
    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    unsigned long argp{ 0 };
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionBio, &argp));

    argp = 1;
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionBio, &argp));

    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::FionRead, &argp));
    ASSERT_TRUE(IoctlSocket(socketHandle, IoctlSocketCmd::Siocatmark, &argp));

    ASSERT_TRUE(CloseSocket(socketHandle));
}

void System::IoctlSocketTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::IoctlSocketTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}
