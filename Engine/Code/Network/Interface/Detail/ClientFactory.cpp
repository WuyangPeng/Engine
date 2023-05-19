///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:48)

#include "Network/NetworkExport.h"

#include "CacheClient.h"
#include "ClientFactory.h"
#include "ClientImpl.h"
#include "NullClient.h"
#include "OnlySendingClient.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::ClientFactory::ClientFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ClientFactory)

Network::ClientFactory::ImplTypeSharedPtr Network::ClientFactory::Create(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager)
{
    switch (const auto clientStrategy = configurationStrategy.GetClientStrategy();
            clientStrategy)
    {
        case ClientStrategy::Cache:
            return make_shared<CacheClient>(configurationStrategy, socketManager);
        case ClientStrategy::OnlySending:
            return make_shared<OnlySendingClient>(configurationStrategy, socketManager);
        default:
            return make_shared<NullClient>(configurationStrategy, socketManager);
    }
}
