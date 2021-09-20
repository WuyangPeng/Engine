// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:39)

#include "BoostSockAcceptorTesting.h" 
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Client.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::make_shared;

Network::BoostSockAcceptorTesting::BoostSockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptorTesting)
void Network::BoostSockAcceptorTesting
	::ClientThread()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DoClientThread);
}

void Network::BoostSockAcceptorTesting
	::DoClientThread()
{
	TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

	auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

	ClientSharedPtr client{ make_shared<Client>(configurationStrategy,testSocketManager) };

	for (auto i = 0; i < sm_ConnectTime; ++i)
	{
		auto socketID = client->Connect();
		if (socketID != 0u)
		{
			break;
		}

		ASSERT_UNEQUAL(i + 1, sm_ConnectTime);
	}
}
