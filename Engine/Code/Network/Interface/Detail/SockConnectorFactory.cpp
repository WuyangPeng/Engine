///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:25)

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

Network::SockConnectorFactory::SockConnectorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockConnectorFactory)

Network::SockConnectorFactory::ImplTypeSharedPtr Network::SockConnectorFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<ACESockConnector>();

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return std::make_shared<BoostSockConnector>();

        case WrappersStrategy::Network:
            return std::make_shared<NetworkSockConnector>();

        case WrappersStrategy::Null:
            return std::make_shared<NullSockConnector>();

        default:
            return std::make_shared<BoostSockConnector>();
    }
}