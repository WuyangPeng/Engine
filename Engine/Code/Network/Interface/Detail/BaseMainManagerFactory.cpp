///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 17:15)

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

using std::make_shared;

Network::BaseMainManagerFactory::BaseMainManagerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BaseMainManagerFactory)

// static
Network::BaseMainManagerFactory::ImplTypePtr Network::BaseMainManagerFactory::Create(const ConfigurationStrategy& configurationStrategy)
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
                return make_shared<BoostMainManager>(CoreTools::DisableNotThrow::Disable);
            }
        }

        case WrappersStrategy::Network:
            return make_shared<NetworkMainManager>(CoreTools::DisableNotThrow::Disable);

        case WrappersStrategy::Socket:
            return make_shared<BoostMainManager>(CoreTools::DisableNotThrow::Disable);

        case WrappersStrategy::Null:
            return make_shared<NullMainManager>();

        case WrappersStrategy::Default:
        default:
            return make_shared<BoostMainManager>(CoreTools::DisableNotThrow::Disable);
    }
}
