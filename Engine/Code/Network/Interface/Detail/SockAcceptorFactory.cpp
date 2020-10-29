//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:51)

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

using std::make_shared;
using std::string;

Network::SockAcceptorFactory::SockAcceptorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptorFactory)

// static
const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockAcceptor>(port);
#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return make_shared<BoostSockAcceptor>(port);

        case WrappersStrategy::Network:
            return make_shared<NetworkSockAcceptor>(port);

        case WrappersStrategy::Null:
            return make_shared<NullSockAcceptor>();

        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockAcceptor>(port);
    }
}

// static
const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory::Create(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockAcceptor>(hostName, port);
#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return make_shared<BoostSockAcceptor>(hostName, port);

        case WrappersStrategy::Network:
            return make_shared<NetworkSockAcceptor>(hostName, port);

        case WrappersStrategy::Null:
            return make_shared<NullSockAcceptor>();

        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockAcceptor>(hostName, port);
    }
}

const Network::SockAcceptorFactory::ImplTypePtr Network::SockAcceptorFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.GetIP().empty())
            {
                return make_shared<BoostSockAcceptor>(configurationStrategy.GetPort());
            }
            else
            {
                return make_shared<BoostSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
            }
        }
        case WrappersStrategy::Network:
            return make_shared<NetworkSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());

        case WrappersStrategy::Null:
            return make_shared<NullSockAcceptor>();

        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockAcceptor>(configurationStrategy.GetIP(), configurationStrategy.GetPort());
    }
}
