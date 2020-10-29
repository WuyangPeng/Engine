//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:51)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "SockAddressFactory.h"
#include "SockAddressImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
#include "Network/BoostWrappers/Detail/Address/BoostSockInetAddress.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"

using std::make_shared;
using std::string;

Network::SockAddressFactory::SockAddressFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressFactory)

// static
const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory::Create(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockInetAddress>(hostName, port);
#endif  // NETWORK_USE_ACE
        case WrappersStrategy::Boost:
            return make_shared<BoostSockInetAddress>(hostName, port);
        case WrappersStrategy::Network:
            return make_shared<NetworkSockInetAddress>(hostName, port);
        case WrappersStrategy::Null:
            return make_shared<NullSockAddress>(hostName, port);
        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockInetAddress>(hostName, port);
    }
}

const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockInetAddress>();
#endif  // NETWORK_USE_ACE
        case WrappersStrategy::Boost:
            return make_shared<BoostSockInetAddress>();
        case WrappersStrategy::Network:
            return make_shared<NetworkSockInetAddress>();
        case WrappersStrategy::Null:
            return make_shared<NullSockAddress>(string{}, 0);
        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockInetAddress>();
    }
}

const Network::SockAddressFactory::ImplTypePtr Network::SockAddressFactory::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACESockInetAddress>(port);
#endif  // NETWORK_USE_ACE
        case WrappersStrategy::Boost:
            return make_shared<BoostSockInetAddress>(port);
        case WrappersStrategy::Network:
            return make_shared<NetworkSockInetAddress>(port);
        case WrappersStrategy::Null:
            return make_shared<NullSockAddress>(string{}, port);
        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSockInetAddress>(port);
    }
}
