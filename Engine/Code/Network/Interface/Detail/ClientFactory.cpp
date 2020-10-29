//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:17)

#include "Network/NetworkExport.h"

#include "CacheClient.h"
#include "ClientFactory.h"
#include "ClientImpl.h"
#include "OnlySendingClient.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::ClientFactory::ClientFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ClientFactory)

// static
const Network::ClientFactory::ImplTypePtr Network::ClientFactory::Create(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
{
    const auto clientStrategyFlag = configurationStrategy.GetClientStrategy();

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
