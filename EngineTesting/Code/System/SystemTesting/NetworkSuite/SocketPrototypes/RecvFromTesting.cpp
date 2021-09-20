///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/07 10:52)

#include "RecvFromTesting.h"
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

System::RecvFromTesting::RecvFromTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, RecvFromTesting)

void System::RecvFromTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::RecvFromTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecvFromTest);
}

void System::RecvFromTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::RecvFromTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::RecvFromTesting::RecvFromTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("UdpPort") + GetEngineeringOffsetValue());
    const auto address = mainTree.get<string>("Address");

    WinSockAddrIn addr{};
    int length{ sizeof(addr) };

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Inet);
    addr.sin_port = System::GetHostToNetShort(port);
    addr.sin_addr.s_addr = System::GetInetAddr(address.c_str());

    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE_FAILURE_THROW(Bind(socketHandle, &addr), "Bind Error");

    constexpr auto bufferSize = 256;
    array<char, bufferSize> buffer{};
    auto index = 0;
    auto remain = bufferSize;

    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("UdpClient")));

    while (0 < remain)
    {
        const auto ret = RecvFrom(socketHandle, &buffer.at(index), remain, SocketRecv::Default, &addr, &length);

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
}
