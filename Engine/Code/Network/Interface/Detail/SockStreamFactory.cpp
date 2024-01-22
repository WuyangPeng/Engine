/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "NullSockStream.h"
#include "SockStreamFactory.h"
#include "SockStreamImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Stream/AceIovecSockStream.h"
#include "Network/ACEWrappers/Detail/Stream/AceSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostFixedSockStream.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSegmentationSockStream.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/Stream/NetworkSockStream.h"

Network::SockStreamFactory::SockStreamFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamFactory)

Network::SockStreamFactory::ImplTypeSharedPtr Network::SockStreamFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
        {
            if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Iovec)
                return std::make_shared<AceIovecSockStream>();
            else
                return std::make_shared<AceSockStream>();
        }

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.GetMessageStrategy() == MessageStrategy::Fixed)
                return std::make_shared<BoostFixedSockStream>(CoreTools::DisableNotThrow::Disable);
            else
                return std::make_shared<BoostSegmentationSockStream>(CoreTools::DisableNotThrow::Disable);
        }

        case WrappersStrategy::Network:
            return std::make_shared<NetworkSockStream>();

        case WrappersStrategy::Null:
            return std::make_shared<NullSockStream>();

        default:
            return std::make_shared<BoostSegmentationSockStream>(CoreTools::DisableNotThrow::Disable);
    }
}