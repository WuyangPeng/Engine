///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 22:18)

#include "SendToTesting.h"
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
#include <vector>

using std::array;
using std::string;
using std::vector;

System::SendToTesting::SendToTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SendToTesting)

void System::SendToTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::SendToTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendToTest);
}

void System::SendToTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::SendToTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::SendToTesting::SendToTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<string>("ConnectHostname");

    WinSockInternetAddress addr{};

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    addr.sin_port = GetHostToNetShort(80);
    addr.sin_addr.s_addr = GetInternetAddress(serverHostname.c_str());

    const auto socketHandle = CreateSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    uint32_t sendNum{ 0 };
    int sendResult{ 0 };
    do
    {
        sendResult = SendTo(socketHandle, iov.data(), boost::numeric_cast<int>(iov.size()), SocketSend::Default, &addr);
        if (sendResult != -1)
        {
            sendNum += sendResult;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());

    ASSERT_TRUE(CloseSocket(socketHandle));
}
