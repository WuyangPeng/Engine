/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:26)

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
