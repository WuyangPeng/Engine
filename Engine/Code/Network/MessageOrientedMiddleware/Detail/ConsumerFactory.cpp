///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 17:01)

#include "Network/NetworkExport.h"

#include "ConsumerFactory.h"
#include "NullConsumer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ActiveMQ/Detail/ActiveMQConsumer.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, ConsumerFactory)

Network::ConsumerFactory::ConsumerSharedPtr Network::ConsumerFactory::Create(const ConfigurationStrategy& configurationStrategy, const System::String& address)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
#ifdef NETWORK_USE_ACTIVE_MQ

        case WrappersStrategy::ActiveMQ:
            return std::make_shared<ActiveMQConsumer>(configurationStrategy, address);

#endif  // NETWORK_USE_ACTIVE_MQ

        default:
            return std::make_shared<NullConsumer>(configurationStrategy);
    }
}
