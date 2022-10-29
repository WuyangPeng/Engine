///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:44)

#include "ShutDownTesting.h"
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

System::ShutDownTesting::ShutDownTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ShutDownTesting)

void System::ShutDownTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::ShutDownTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Receive);
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Send);
    ASSERT_NOT_THROW_EXCEPTION_1(ShutDownTest, ShutdownHow::Both);
}

void System::ShutDownTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::ShutDownTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::ShutDownTesting::ShutDownTest(ShutdownHow shutdownHow)
{
    boost::property_tree::basic_ptree<string, string> mainTree{};

    read_json("Configuration/EnvironmentVariable.json", mainTree);

    const auto serverHostname = mainTree.get<string>("ConnectHostname");

    WinSockInternetAddress addr{};

    addr.sin_family = EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    addr.sin_port = GetHostToNetShort(80);
    addr.sin_addr.s_addr = GetInternetAddress(serverHostname.c_str());

    const WinSocket socketHandle = CreateSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    ASSERT_TRUE(Connect(socketHandle, &addr));

    ASSERT_TRUE(ShutDown(socketHandle, shutdownHow));

    ASSERT_TRUE(CloseSocket(socketHandle));
}
