///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:46)

#include "WinSocketRecvFromTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <vector>

using std::array;
using std::string;
using std::vector;

System::WinSocketRecvFromTesting::WinSocketRecvFromTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketRecvFromTesting)

void System::WinSocketRecvFromTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::WinSocketRecvFromTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RecvFromTest);
}

void System::WinSocketRecvFromTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::WinSocketRecvFromTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::WinSocketRecvFromTesting::RecvFromTest()
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto port = boost::numeric_cast<uint16_t>(mainTree.get<uint16_t>("UdpPort") + GetEngineeringOffsetValue());
    const auto address = mainTree.get<string>("Address");

    WinSockInternetAddress addr{};
    int length{ sizeof(addr) };

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    addr.sin_port = System::GetHostToNetShort(port);
    addr.sin_addr.s_addr = System::GetInternetAddress(address.c_str());

    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp, nullptr, 0, 0);

    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE_FAILURE_THROW(Bind(socketHandle, &addr), "Bind Error");

    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("UdpClient")));

    constexpr auto bufferSize = 256;
    array<char, bufferSize> bufferArray{};
    WinSockBuf buffer{};

    auto index = 0;
    auto remain = bufferSize;

    while (0 < remain)
    {
        WindowsDWord numberOfBytesRecvd{ 0 };
        WindowsDWord flags{ 0 };

        buffer.buf = &bufferArray.at(index);
        buffer.len = remain;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto ret = WinSocketRecvFrom(socketHandle, &buffer, 1, &numberOfBytesRecvd, &flags, reinterpret_cast<WinSockAddr*>(&addr), &length, nullptr, nullptr);

#include STSTEM_WARNING_POP

        ASSERT_UNEQUAL(ret, gSocketError);

        if (ret == gSocketError)
        {
            break;
        }

        remain -= numberOfBytesRecvd;
        index += numberOfBytesRecvd;
    }

    string result{ bufferArray.data() };

    ASSERT_EQUAL(result, "Hello");

    ASSERT_TRUE(CloseSocket(socketHandle));
}
