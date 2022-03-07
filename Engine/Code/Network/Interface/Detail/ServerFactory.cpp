///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 23:47)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "NullServer.h"
#include "ReactiveServer.h"
#include "ServerFactory.h"
#include "ServerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;
using std::string;

Network::ServerFactory::ServerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServerFactory)

// static
Network::ServerFactory::ImplTypeSharedPtr Network::ServerFactory::Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
{
    const auto patternStrategyFlag = configurationStrategy.GetPatternStrategy();

    switch (patternStrategyFlag)
    {
        case ServerStrategy::Iterative:
            return make_shared<IterativeServer>(socketManager, configurationStrategy);
        case ServerStrategy::Reactive:
            return make_shared<ReactiveServer>(socketManager, configurationStrategy);
        default:
            return make_shared<NullServer>(socketManager, configurationStrategy);
    }
}