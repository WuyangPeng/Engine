// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 09:59)

#include "Network/NetworkExport.h" 

#include "BaseMainManagerFactory.h"
#include "BaseMainManagerImpl.h"
#include "NullMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ACEWrappers/Detail/BaseMainManager/ACEMainManager.h" 
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManager.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseThreads.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseMultiContext.h"
#include "Network/NetworkWrappers/Detail/BaseMainManager/NetworkMainManager.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::BaseMainManagerFactory
	::BaseMainManagerFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerFactory)
	
// static
const Network::BaseMainManagerFactory::ImplTypePtr Network::BaseMainManagerFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<ACEMainManager>();
#endif // NETWORK_USE_ACE	

	case WrappersStrategy::Boost:
	{
		if(configurationStrategy.IsExist(WrappersSubStrategy::Threads))
		{
			return make_shared<BoostMainManagerUseThreads>(configurationStrategy.GetConfigurationSubStrategy()); 
		}
		else if(configurationStrategy.IsExist(WrappersSubStrategy::MultiContext))
		{
			return make_shared<BoostMainManagerUseMultiContext>(configurationStrategy.GetConfigurationSubStrategy()); 
		}
		else
		{
			return make_shared<BoostMainManager>(); 
		}
	}

	case WrappersStrategy::Network:
		return make_shared<NetworkMainManager>(); 

	case WrappersStrategy::Socket:
		return make_shared<BoostMainManager>();

	case WrappersStrategy::Null:
		return make_shared<NullMainManager>();		

	case WrappersStrategy::Default:
	default:
		return make_shared<BoostMainManager>(); 
	}
}

