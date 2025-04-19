/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:31)

#include "Network/NetworkExport.h"

#include "BaseMainManagerFactory.h"
#include "BaseMainManagerImpl.h"
#include "NullMainManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/AceWrappers/Detail/BaseMainManager/AceMainManager.h"
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
            return std::make_shared<AceMainManager>();
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
