//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:10)

#include "Network/NetworkExport.h"

#include "BaseMainManagerFactory.h"
#include "BaseMainManagerImpl.h"
#include "NullMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/BaseMainManager/ACEMainManager.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManager.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseMultiContext.h"
#include "Network/BoostWrappers/Detail/BaseMainManager/BoostMainManagerUseThreads.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkWrappers/Detail/BaseMainManager/NetworkMainManager.h"

using std::make_shared;

Network::BaseMainManagerFactory::BaseMainManagerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerFactory)

// static
const Network::BaseMainManagerFactory::ImplTypePtr Network::BaseMainManagerFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<ACEMainManager>();
#endif  // NETWORK_USE_ACE

        case WrappersStrategy::Boost:
        {
            if (configurationStrategy.IsExist(WrappersSubStrategy::Threads))
            {
                return make_shared<BoostMainManagerUseThreads>(configurationStrategy.GetConfigurationSubStrategy());
            }
            else if (configurationStrategy.IsExist(WrappersSubStrategy::MultiContext))
            {
                return make_shared<BoostMainManagerUseMultiContext>(configurationStrategy.GetConfigurationSubStrategy());
            }
            else
            {
                return make_shared<BoostMainManager>();
            }
        }

        case WrappersStrategy::Network:
            return make_shared<NetworkMainManager>();

        case WrappersStrategy::Socket:
            return make_shared<BoostMainManager>();

        case WrappersStrategy::Null:
            return make_shared<NullMainManager>();

        case WrappersStrategy::Default:
        default:
            return make_shared<BoostMainManager>();
    }
}
