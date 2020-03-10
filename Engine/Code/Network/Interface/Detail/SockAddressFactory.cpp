// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/20 17:39)

#include "Network/NetworkExport.h" 

#include "SockAddressFactory.h"
#include "SockAddressImpl.h"
#include "NullSockAddress.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
#include "Network/BoostWrappers/Detail/Address/BoostSockInetAddress.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::make_shared;

Network::SockAddressFactory
	::SockAddressFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network,SockAddressFactory)
	
// static
const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory
	::Create(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockInetAddress>(hostName, port); 
#endif // NETWORK_USE_ACE
	case WrappersStrategy::Boost:
		return make_shared<BoostSockInetAddress>(hostName, port);
	case WrappersStrategy::Network:
		return make_shared<NetworkSockInetAddress>(hostName, port);	 
	case WrappersStrategy::Null:
		return make_shared<NullSockAddress>(hostName, port);
	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockInetAddress>(hostName, port);
	}	
}

const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockInetAddress>();
#endif // NETWORK_USE_ACE
	case WrappersStrategy::Boost:
		return make_shared<BoostSockInetAddress>();
	case WrappersStrategy::Network:
		return make_shared<NetworkSockInetAddress>();
	case WrappersStrategy::Null:
		return make_shared<NullSockAddress>("", 0);
	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockInetAddress>();
	}	
}

const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory
	::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockInetAddress>(port);
#endif // NETWORK_USE_ACE
	case WrappersStrategy::Boost:
		return make_shared<BoostSockInetAddress>(port);
	case WrappersStrategy::Network:
		return make_shared<NetworkSockInetAddress>(port);
	case WrappersStrategy::Null:
		return make_shared<NullSockAddress>("", port);
	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockInetAddress>(port);
	}
}

