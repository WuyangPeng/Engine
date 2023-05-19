///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 17:01)

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

        case WrappersStrategy::ActiveMQ:
            return std::make_shared<ActiveMQProducer>(configurationStrategy);

#endif  // NETWORK_USE_ACTIVE_MQ

        default:
            return std::make_shared<NullProducer>(configurationStrategy);
    }
}
