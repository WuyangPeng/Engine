///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:37)

#include "BoostSockAcceptorTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/Client.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"

Network::BoostSockAcceptorTesting::BoostSockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorTesting)

void Network::BoostSockAcceptorTesting::ClientThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientThread);
}

void Network::BoostSockAcceptorTesting::DoClientThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();

    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    Client client{ configurationStrategy, messageEventManager };

    for (auto i = 0; i < connectTime; ++i)
    {
        if (const auto socketId = client.Connect();
            socketId != 0u)
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }
}
