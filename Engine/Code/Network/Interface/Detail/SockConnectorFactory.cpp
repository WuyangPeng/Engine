//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:53)

#include "Network/NetworkExport.h"

#include "NullSockConnector.h"
#include "SockConnectorFactory.h"
#include "SockConnectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Connector/ACESockConnector.h"
#include "Network/BoostWrappers/Detail/Connector/BoostSockConnector.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Connector/NetworkSockConnector.h"

using std::make_shared;

Network::SockConnectorFactory::SockConnectorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockConnectorFactory)

// static
const Network::SockConnectorFactory::ImplTypePtr Network::SockConnectorFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::ACE:
            return make_shared<ACESockConnector>();

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return make_shared<BoostSockConnector>();

        case WrappersStrategy::Network:
            return make_shared<NetworkSockConnector>();

        case WrappersStrategy::Null:
            return make_shared<NullSockConnector>();

        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockConnector>();
    }
}