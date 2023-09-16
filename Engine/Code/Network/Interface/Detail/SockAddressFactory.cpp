///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:22)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "SockAddressFactory.h"
#include "SockAddressImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Address/AceSockInternetAddress.h"
#include "Network/BoostWrappers/Detail/Address/BoostSockInternetAddress.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInternetAddress.h"

Network::SockAddressFactory::SockAddressFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressFactory)

Network::SockAddressFactory::ImplTypeSharedPtr Network::SockAddressFactory::Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return make_shared<AceSockInternetAddress>(hostName, port);

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return make_shared<BoostSockInternetAddress>(hostName, port);
        case WrappersStrategy::Network:
            return make_shared<NetworkSockInternetAddress>(hostName, port);
        case WrappersStrategy::Null:
            return make_shared<NullSockAddress>(hostName, port);

        default:
            return make_shared<BoostSockInternetAddress>(hostName, port);
    }
}

Network::SockAddressFactory::ImplTypeSharedPtr Network::SockAddressFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<AceSockInternetAddress>();

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return std::make_shared<BoostSockInternetAddress>();
        case WrappersStrategy::Network:
            return std::make_shared<NetworkSockInternetAddress>(CoreTools::DisableNotThrow::Disable);
        case WrappersStrategy::Null:
            return std::make_shared<NullSockAddress>(0);

        default:
            return std::make_shared<BoostSockInternetAddress>();
    }
}

Network::SockAddressFactory::ImplTypeSharedPtr Network::SockAddressFactory::Create(int port, const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<AceSockInternetAddress>(port);

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
            return std::make_shared<BoostSockInternetAddress>(port);
        case WrappersStrategy::Network:
            return std::make_shared<NetworkSockInternetAddress>(port);
        case WrappersStrategy::Null:
            return std::make_shared<NullSockAddress>(port);

        default:
            return std::make_shared<BoostSockInternetAddress>(port);
    }
}
