// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 11:28)

#include "Network/NetworkExport.h" 

#include "SockStreamFactory.h"
#include "SockStreamImpl.h"
#include "NullSockStream.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/ACEWrappers/Detail/Stream/ACESockStream.h"
#include "Network/ACEWrappers/Detail/Stream/ACEIovecSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostFixedSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSegmentationSockStream.h"
#include "Network/NetworkWrappers/Detail/Stream/NetworkSockStream.h"

using std::make_shared;

Network::SockStreamFactory
	::SockStreamFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamFactory)

// static
const Network::SockStreamFactory::ImplTypePtr Network::SockStreamFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
	{
		if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Iovec)
			return make_shared<ACEIovecSockStream>();
		else
			return make_shared<ACESockStream>();
	}
#endif // NETWORK_USE_ACE

	case WrappersStrategy::Boost:
	{
		if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Fixed)
			return make_shared<BoostFixedSockStream>();
		else
			return make_shared<BoostSegmentationSockStream>();
	}

	case WrappersStrategy::Network:
		return make_shared<NetworkSockStream>();

	case WrappersStrategy::Null:
		return make_shared<NullSockStream>();

	case WrappersStrategy::Socket:
	case WrappersStrategy::Default:
	default:
		return make_shared<BoostSegmentationSockStream>();
	}
}