/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:14)

#include "GetWinSocketTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetWinSocketTesting::GetWinSocketTesting(const OStreamShared& stream)
    : ParentType{ stream },
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
    std::ranges::shuffle(protocolFamilies, randomEngine);
    std::ranges::shuffle(socketTypes, randomEngine);
    std::ranges::shuffle(socketProtocols, randomEngine);

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
