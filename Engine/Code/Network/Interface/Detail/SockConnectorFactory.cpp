/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:29)

#include "Network/NetworkExport.h"

#include "NullSockConnector.h"
#include "SockConnectorFactory.h"
#include "SockConnectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Connector/AceSockConnector.h"
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
            return std::make_shared<AceSockConnector>();

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