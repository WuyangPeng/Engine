///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 13:59)

#include "BoostSockAcceptorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/Client.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
using std::make_shared;

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    ClientSharedPtr client{ make_shared<Client>(configurationStrategy, std::make_shared<MessageEventManager>(MessageEventManager::Create())) };

#include STSTEM_WARNING_POP

    for (auto i = 0; i < connectTime; ++i)
    {
        const auto socketID = client->Connect();
        if (socketID != 0u)
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, connectTime);
    }
}
