// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:25)

#include "Network/NetworkExport.h" 

#include "ServerFactory.h"
#include "ServerImpl.h"
#include "IterativeServer.h"
#include "ReactiveServer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
using std::make_shared;

Network::ServerFactory
	::ServerFactory()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_STUB_DEFINE(Network,ServerFactory)

// static
const Network::ServerFactory::ImplTypePtr Network::ServerFactory
	::Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
{
	auto patternStrategyFlag = configurationStrategy.GetPatternStrategy();

	switch (patternStrategyFlag)
	{
	case ServerStrategy::Iterative:
		return make_shared<IterativeServer>(socketManager,configurationStrategy);
	case ServerStrategy::Reactive:
		return make_shared<ReactiveServer>(socketManager, configurationStrategy);
	default:
		return make_shared<ImplType>(socketManager,configurationStrategy);
	}
}