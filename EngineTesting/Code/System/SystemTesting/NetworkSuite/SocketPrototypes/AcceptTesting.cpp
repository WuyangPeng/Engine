///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/05 19:49)

#include "AcceptTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::string;

System::AcceptTesting::AcceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AcceptTesting)

void System::AcceptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::AcceptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AcceptTest);
}

void System::AcceptTesting::AcceptTest()
{
    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("TcpClient")));

    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("TcpPort") + GetEngineeringOffsetValue());

    WinSockAddrIn addr{};

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Inet);
    addr.sin_port = GetHostToNetShort(port);
    addr.sin_addr.s_addr = GetHostToNetLong(g_InAddrAny);

    int addrLen{ sizeof(addr) };

    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE(Bind(socketHandle, &addr));
    ASSERT_TRUE(Listen(socketHandle, 5));

    GetStream() << "调用accept等待客户端连接！\n";
    const WinSocket acceptHandle = Accept(socketHandle, &addr, &addrLen);
    ASSERT_TRUE(IsSocketValid(acceptHandle));

    constexpr auto bufferSize = 256;
    array<char, bufferSize> buffer{};
    int index{ 0 };
    int remain{ bufferSize };

    while (0 < remain)
    {
        const auto ret = Recv(acceptHandle, &buffer.at(index), remain, SocketRecv::Default);

        ASSERT_UNEQUAL(ret, g_SocketError);

        if (ret == g_SocketError)
        {
            break;
        }

        remain -= ret;
        index += ret;
    }

    string result{ buffer.data() };

    ASSERT_EQUAL(result, "Hello");

    ASSERT_TRUE(CloseSocket(socketHandle));
    ASSERT_TRUE(CloseSocket(acceptHandle));
}

void System::AcceptTesting::Init()
{
    // 初始化WinSock
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::AcceptTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}
