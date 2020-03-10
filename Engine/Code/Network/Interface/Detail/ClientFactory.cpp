// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/01 17:17)

#include "Network/NetworkExport.h" 

#include "ClientFactory.h"
#include "ClientImpl.h"
#include "CacheClient.h"
#include "OnlySendingClient.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

using std::make_shared;

Network::ClientFactory
	::ClientFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network,ClientFactory)
	
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

