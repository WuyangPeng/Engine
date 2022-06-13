///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:45)

#include "SocketNameTesting.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::string;
using std::vector;

System::SocketNameTesting::SocketNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SocketNameTesting)

void System::SocketNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::SocketNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SocketNameTest);
}

void System::SocketNameTesting::Init()
{
    // 初始化WinSock
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::SocketNameTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::SocketNameTesting::SocketNameTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<string>("ConnectHostname");

    WinSockAddrIn addr{};

    addr.sin_family = static_cast<short>(AddressFamilies::Inet);
    addr.sin_port = GetHostToNetShort(80);
    addr.sin_addr.s_addr = GetInetAddr(serverHostname.c_str());

    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "获取socket失败。");

    ASSERT_TRUE(Connect(socketHandle, &addr));

    WinSockAddrIn peerName{};
    int peerNameSize{ sizeof(WinSockAddrIn) };

    ASSERT_TRUE(GetPeerName(socketHandle, &peerName, &peerNameSize));

    WinSockAddrIn sockName = {};
    int sockNameSize{ sizeof(WinSockAddrIn) };

    ASSERT_TRUE(GetSockName(socketHandle, &sockName, &sockNameSize));

    auto newAddr = InetNtoa(peerName.sin_addr);
    ASSERT_EQUAL(serverHostname, newAddr);

    ASSERT_EQUAL(addr.sin_family, peerName.sin_family);
    ASSERT_EQUAL(addr.sin_port, peerName.sin_port);
    ASSERT_EQUAL(addr.sin_addr.s_addr, peerName.sin_addr.s_addr);

    ASSERT_TRUE(CloseSocket(socketHandle));
}
