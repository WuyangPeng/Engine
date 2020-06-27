// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:26)

#include "Network/NetworkExport.h" 

#include "SockAcceptorFactory.h"
#include "SockAcceptorImpl.h"
#include "NullSockAcceptor.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ACEWrappers/Detail/Acceptor/ACESockAcceptor.h"
#include "Network/BoostWrappers/Detail/Acceptor/BoostSockAcceptor.h"
#include "Network/NetworkWrappers/Detail/Acceptor/NetworkSockAcceptor.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::make_shared;

Network::SockAcceptorFactory
	::SockAcceptorFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptorFactory)

// static
const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory
	::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{

#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockAcceptor>(port);
#endif // NETWORK_USE_ACE

	case WrappersStrategy::Boost:
		return make_shared<BoostSockAcceptor>(port);

	case WrappersStrategy::Network:
		return make_shared<NetworkSockAcceptor>(port);

	case WrappersStrategy::Null:
		return make_shared<NullSockAcceptor>();

	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockAcceptor>(port);
	}
}

// static
const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory
	::Create(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{

#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockAcceptor>(hostName, port);
#endif // NETWORK_USE_ACE

	case WrappersStrategy::Boost:
		return make_shared<BoostSockAcceptor>(hostName, port);

	case WrappersStrategy::Network:
		return make_shared<NetworkSockAcceptor>(hostName, port);

	case WrappersStrategy::Null:
		return make_shared<NullSockAcceptor>();

	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockAcceptor>(hostName, port);
	}
}

const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{

#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACESockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
#endif // NETWORK_USE_ACE

	case WrappersStrategy::Boost:
	{
		if (configurationStrategy.GetIP().empty())
		{
			return make_shared<BoostSockAcceptor>(configurationStrategy.GetPort());
		}
		else
		{
			return make_shared<BoostSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
		}
	}
	case WrappersStrategy::Network:
		return make_shared<NetworkSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());

	case WrappersStrategy::Null:
		return make_shared<NullSockAcceptor>();

	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
	}
}
