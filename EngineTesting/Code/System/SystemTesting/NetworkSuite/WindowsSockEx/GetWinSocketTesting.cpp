///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/11 20:24)

#include "GetWinSocketTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetWinSocketTesting::GetWinSocketTesting(const OStreamShared& tream)
    : ParentType{ tream },
      protocolFamilies{ ProtocolFamilies::Inet },
      socketTypes{ SocketTypes::Dgram, SocketTypes::Stream },
      socketProtocols{ SocketProtocols::Ip, SocketProtocols::Tcp, SocketProtocols::Udp },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ protocolFamilies.size(), socketTypes.size(), socketProtocols.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetWinSocketTesting)

void System::GetWinSocketTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::GetWinSocketTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::GetWinSocketTesting::RandomShuffleFlags()
{
    shuffle(protocolFamilies.begin(), protocolFamilies.end(), randomEngine);
    shuffle(socketTypes.begin(), socketTypes.end(), randomEngine);
    shuffle(socketProtocols.begin(), socketProtocols.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(GetSocketTest);

    return true;
}

void System::GetWinSocketTesting::GetSocketTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetSocketTest, index);
    }
}

void System::GetWinSocketTesting::DoGetSocketTest(size_t index)
{
    const auto protocolFamily = protocolFamilies.at(index % protocolFamilies.size());
    const auto socketProtocol = socketProtocols.at(index % socketProtocols.size());

    auto socketType = socketTypes.at(index % socketTypes.size());
    if (socketProtocol == SocketProtocols::Tcp)
    {
        socketType = SocketTypes::Stream;
    }
    else if (socketProtocol == SocketProtocols::Udp)
    {
        socketType = SocketTypes::Dgram;
    }

    const auto winSocket = GetWinSocket(protocolFamily, socketType, socketProtocol, nullptr, 0, 0);

    ASSERT_TRUE(IsSocketValid(winSocket));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, winSocket);
}
