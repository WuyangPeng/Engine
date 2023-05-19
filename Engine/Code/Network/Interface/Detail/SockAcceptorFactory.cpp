///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:13)

#include "Network/NetworkExport.h"

#include "NullSockAcceptor.h"
#include "SockAcceptorFactory.h"
#include "SockAcceptorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Acceptor/ACESockAcceptor.h"
#include "Network/BoostWrappers/Detail/Acceptor/BoostSockAcceptor.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Acceptor/NetworkSockAcceptor.h"

Network::SockAcceptorFactory::SockAcceptorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptorFactory)

Network::SockAcceptorFactory::ImplTypeSharedPtr Network::SockAcceptorFactory::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<ACESockAcceptor>(port);

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return std::make_shared<BoostSockAcceptor>(port);

        case WrappersStrategy::Network:
            return std::make_shared<NetworkSockAcceptor>(port);

        case WrappersStrategy::Null:
            return std::make_shared<NullSockAcceptor>();

        default:
            return std::make_shared<BoostSockAcceptor>(port);
    }
}

Network::SockAcceptorFactory::ImplTypeSharedPtr Network::SockAcceptorFactory::Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return make_shared<ACESockAcceptor>(hostName, port);

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return make_shared<BoostSockAcceptor>(hostName, port);

        case WrappersStrategy::Network:
            return make_shared<NetworkSockAcceptor>(hostName, port);

        case WrappersStrategy::Null:
            return std::make_shared<NullSockAcceptor>();

        default:
            return make_shared<BoostSockAcceptor>(hostName, port);
    }
}

Network::SockAcceptorFactory::ImplTypeSharedPtr Network::SockAcceptorFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return make_shared<ACESockAcceptor>(configurationStrategy.GetHost(), configurationStrategy.GetPort());

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.GetHost().empty())
            {
                return std::make_shared<BoostSockAcceptor>(configurationStrategy.GetPort());
            }
            else
            {
                return make_shared<BoostSockAcceptor>(configurationStrategy.GetHost(), configurationStrategy.GetPort());
            }
        }
        case WrappersStrategy::Network:
            return make_shared<NetworkSockAcceptor>(configurationStrategy.GetHost(), configurationStrategy.GetPort());

        case WrappersStrategy::Null:
            return std::make_shared<NullSockAcceptor>();

        default:
            return make_shared<BoostSockAcceptor>(configurationStrategy.GetHost(), configurationStrategy.GetPort());
    }
}
