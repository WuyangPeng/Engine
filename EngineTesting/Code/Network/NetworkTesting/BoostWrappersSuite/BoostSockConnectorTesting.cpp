// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:39)

#include "BoostSockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::make_shared;
using std::string;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
Network::BoostSockConnectorTesting::BoostSockConnectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockConnectorTesting)

void Network::BoostSockConnectorTesting ::ServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerThread);
}

void Network::BoostSockConnectorTesting ::DoServerThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    for (auto i = 0; i < sm_AcceptTime; ++i)
    {
        [[maybe_unused]] const auto value = server->RunServer();

        if (0 < testSocketManager->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sm_AcceptTime);
    }
}
