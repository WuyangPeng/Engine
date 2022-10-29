///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:42)

#include "ConnectTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

using std::array;
using std::string;
using std::vector;

System::ConnectTesting::ConnectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConnectTesting)

void System::ConnectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::ConnectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConnectTest);
}

void System::ConnectTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::ConnectTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::ConnectTesting::ConnectTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<string>("ConnectHostname");

    WinSockInternetAddress addr{};

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    addr.sin_port = GetHostToNetShort(80);
    addr.sin_addr.s_addr = GetInternetAddress(serverHostname.c_str());

    const auto socketHandle = CreateSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE(Connect(socketHandle, &addr));

    string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    uint32_t sendNum{ 0 };

    do
    {
        const auto sendResult = Send(socketHandle, iov.data(), boost::numeric_cast<int>(iov.size()), SocketSend::Default);
        if (sendResult != -1)
        {
            sendNum += sendResult;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());

    constexpr auto buffSize = 1024;

    array<char, buffSize> buf{};

    auto result = 0;
    do
    {
        result = Recv(socketHandle, buf.data(), buffSize, SocketRecv::Default);
        ASSERT_LESS_EQUAL(result, buffSize);
        GetStream() << "收到的数据为：" << buf.data() << "\n";
    } while (0 < result);

    ASSERT_TRUE(CloseSocket(socketHandle));
}
