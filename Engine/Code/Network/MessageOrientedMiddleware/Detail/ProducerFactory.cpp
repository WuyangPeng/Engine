///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:33)

#include "Network/NetworkExport.h"

#include "NullProducer.h"
#include "ProducerFactory.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ActiveMQ/Detail/ActiveMQProducer.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, ProducerFactory)

Network::ProducerFactory::ProducerSharedPtr Network::ProducerFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
#ifdef NETWORK_USE_ACTIVE_MQ

        case WrappersStrategy::ActiveMq:
            return std::make_shared<ActiveMQProducer>(configurationStrategy);

#endif  // NETWORK_USE_ACTIVE_MQ

        default:
            return std::make_shared<NullProducer>(configurationStrategy);
    }
}
