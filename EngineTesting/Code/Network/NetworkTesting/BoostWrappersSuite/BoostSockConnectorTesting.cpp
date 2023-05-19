///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:43)

#include "BoostSockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"

Network::BoostSockConnectorTesting::BoostSockConnectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockConnectorTesting)

void Network::BoostSockConnectorTesting::ServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerThread);
}

void Network::BoostSockConnectorTesting::DoServerThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();

    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    Server server{ configurationStrategy, messageEventManager };

    for (auto i = 0; i < acceptTime; ++i)
    {
        MAYBE_UNUSED const auto result = server.RunServer();

        if (0 < testSocketEvent->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }
}
