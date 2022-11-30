///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 22:14)

#include "WinSocketSendToTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

using std::array;
using std::string;
using std::vector;

System::WinSocketSendToTesting::WinSocketSendToTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketSendToTesting)

void System::WinSocketSendToTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::WinSocketSendToTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendToTest);
}

void System::WinSocketSendToTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::WinSocketSendToTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::WinSocketSendToTesting::SendToTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<string>("ConnectHostname");

    WinSockInternetAddress addr{};
    constexpr int length{ sizeof(WinSockInternetAddress) };

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    addr.sin_port = GetHostToNetShort(80);
    addr.sin_addr.s_addr = GetInternetAddress(serverHostname.c_str());

    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp, nullptr, 0, 0);

    ASSERT_TRUE(IsSocketValid(socketHandle));

    string sendMessage{ "GET /index.html HTTP/1.0\r\n\r\n" };

    vector<char> iov{ sendMessage.begin(), sendMessage.end() };

    uint32_t sendNum{ 0 };

    WinSockBuf buffer{};

    do
    {
        buffer.buf = &iov.at(sendNum);
        buffer.len = boost::numeric_cast<uint32_t>(iov.size() - sendNum);

        auto numberOfBytesSent = boost::numeric_cast<WindowsDWord>(iov.size());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto sendResult = WinSocketSendTo(socketHandle, &buffer, 1, &numberOfBytesSent, 0, reinterpret_cast<const WinSockAddr*>(&addr), length, nullptr, nullptr);

#include STSTEM_WARNING_POP

        if (sendResult != -1)
        {
            sendNum += numberOfBytesSent;
        }
        else
        {
            break;
        }

    } while (sendNum < iov.size());

    ASSERT_TRUE(CloseSocket(socketHandle));
}
