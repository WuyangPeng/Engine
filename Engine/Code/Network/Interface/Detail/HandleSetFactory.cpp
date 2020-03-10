// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:19)

#include "Network/NetworkExport.h" 

#include "HandleSetFactory.h"
#include "HandleSetImpl.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ACEWrappers/Detail/Acceptor/SockACEHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::HandleSetFactory
	::HandleSetFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network,HandleSetFactory)
	
// static
const Network::HandleSetFactory::ImplTypePtr Network::HandleSetFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategyFlag)
	{
#ifdef NETWORK_USE_ACE
	case WrappersStrategy::ACE:
		return make_shared<SockACEHandleSet>();
#endif // NETWORK_USE_ACE		
	default:
		return make_shared<ImplType>();
	}
}

