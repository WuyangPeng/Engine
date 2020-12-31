//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:53)

#include "Network/NetworkExport.h"

#include "NullSockStream.h"
#include "SockStreamFactory.h"
#include "SockStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Stream/ACEIovecSockStream.h"
#include "Network/ACEWrappers/Detail/Stream/ACESockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostFixedSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSegmentationSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Stream/NetworkSockStream.h"

using std::make_shared;

Network::SockStreamFactory::SockStreamFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamFactory)

// static
const Network::SockStreamFactory::ImplTypePtr Network::SockStreamFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
        {
            if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Iovec)
                return make_shared<ACEIovecSockStream>();
            else
                return make_shared<ACESockStream>();
        }
#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Fixed)
                return make_shared<BoostFixedSockStream>();
            else
                return make_shared<BoostSegmentationSockStream>();
        }

        case WrappersStrategy::Network:
            return make_shared<NetworkSockStream>();

        case WrappersStrategy::Null:
            return make_shared<NullSockStream>();

        case WrappersStrategy::Socket:
        case WrappersStrategy::Default:
        default:
            return make_shared<BoostSegmentationSockStream>();
    }
}