///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:42)

#include "GetSocketTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSocketTesting::GetSocketTesting(const OStreamShared& tream)
    : ParentType{ tream },
      protocolFamiliesFlags{ ProtocolFamilies::Inet },
      socketTypesFlags{ SocketTypes::Dgram, SocketTypes::Stream },
      socketProtocolsFlags{ SocketProtocols::Ip, SocketProtocols::Tcp, SocketProtocols::Udp },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ protocolFamiliesFlags.size(), socketTypesFlags.size(), socketProtocolsFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSocketTesting)

void System::GetSocketTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::GetSocketTesting::Init()
{
    // 初始化WinSock
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::GetSocketTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::GetSocketTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::GetSocketTesting::RandomShuffleFlags()
{
    shuffle(protocolFamiliesFlags.begin(), protocolFamiliesFlags.end(), randomEngine);
    shuffle(socketTypesFlags.begin(), socketTypesFlags.end(), randomEngine);
    shuffle(socketProtocolsFlags.begin(), socketProtocolsFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(GetSocketTest);

    return true;
}

void System::GetSocketTesting::GetSocketTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        auto protocolFamilies = protocolFamiliesFlags.at(index % protocolFamiliesFlags.size());
        auto socketTypes = socketTypesFlags.at(index % socketTypesFlags.size());
        auto socketProtocols = socketProtocolsFlags.at(index % socketProtocolsFlags.size());

        if (socketProtocols == SocketProtocols::Tcp)
        {
            socketTypes = SocketTypes::Stream;
        }
        else if (socketProtocols == SocketProtocols::Udp)
        {
            socketTypes = SocketTypes::Dgram;
        }

        const auto winSocket = CreateSocket(protocolFamilies, socketTypes, socketProtocols);

        ASSERT_TRUE(IsSocketValid(winSocket));

        ASSERT_TRUE(CloseSocket(winSocket));
    }
}
