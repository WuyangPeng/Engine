///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/08 17:25)

#include "Network/NetworkExport.h"

#include "BaseMainManagerFactory.h"
#include "BaseMainManagerImpl.h"
#include "NullMainManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/BaseMainManager/ACEMainManager.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManager.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseMultiContext.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseThreads.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/BaseMainManager/NetworkMainManager.h"

Network::BaseMainManagerFactory::BaseMainManagerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerFactory)

Network::BaseMainManagerFactory::ImplTypePtr Network::BaseMainManagerFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();
            wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
        {
            return std::make_shared<ACEMainManager>();
        }

#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.IsExist(WrappersSubStrategy::Threads))
            {
                return std::make_shared<BoostMainManagerUseThreads>(configurationStrategy.GetConfigurationSubStrategy());
            }
            else if (configurationStrategy.IsExist(WrappersSubStrategy::MultiContext))
            {
                return std::make_shared<BoostMainManagerUseMultiContext>(configurationStrategy.GetConfigurationSubStrategy());
            }
            else
            {
                return std::make_shared<BoostMainManager>(CoreTools::DisableNotThrow::Disable);
            }
        }

        case WrappersStrategy::Network:
        {
            return std::make_shared<NetworkMainManager>(CoreTools::DisableNotThrow::Disable);
        }

        case WrappersStrategy::Null:
        {
            return std::make_shared<NullMainManager>();
        }

        default:
        {
            return std::make_shared<BoostMainManager>(CoreTools::DisableNotThrow::Disable);
        }
    }
}
