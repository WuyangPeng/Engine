// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:02)

#include "Network/NetworkExport.h" 

#include "ClientFactory.h"
#include "ClientImpl.h"
#include "CacheClient.h"
#include "OnlySendingClient.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::ClientFactory
	::ClientFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ClientFactory)

// static
const Network::ClientFactory::ImplTypePtr Network::ClientFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
{
	auto clientStrategyFlag = configurationStrategy.GetClientStrategy();

	switch (clientStrategyFlag)
	{
	case ClientStrategy::Cache:
		return make_shared<CacheClient>(configurationStrategy, socketManager);
	case ClientStrategy::OnlySending:
		return make_shared<OnlySendingClient>(configurationStrategy, socketManager);
	default:
		return make_shared<ImplType>(configurationStrategy, socketManager);
	}
}

