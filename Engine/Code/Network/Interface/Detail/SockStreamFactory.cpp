// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/23 10:06)

#include "Network/NetworkExport.h" 

#include "SockStreamFactory.h"
#include "SockStreamImpl.h"
#include "NullSockStream.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ACEWrappers/Detail/Stream/ACESockStream.h"
#include "Network/ACEWrappers/Detail/Stream/ACEIovecSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostFixedSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSegmentationSockStream.h"
#include "Network/NetworkWrappers/Detail/Stream/NetworkSockStream.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::SockStreamFactory
	::SockStreamFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
} 

CLASS_INVARIANT_STUB_DEFINE(Network,SockStreamFactory)
	 
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