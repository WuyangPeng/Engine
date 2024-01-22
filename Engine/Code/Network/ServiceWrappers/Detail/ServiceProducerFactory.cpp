/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:57)

#include "Network/NetworkExport.h"

#include "NullServiceProducer.h"
#include "ServiceProducerFactory.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Service/AceTcpClientServiceProducer.h"
#include "Network/ACEWrappers/Detail/Service/AceTcpServerServiceProducer.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpClientServiceProducer.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpServerServiceProducer.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceProducerFactory)

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    if (configurationStrategy.IsClient())
    {
        return CreateClient(configurationStrategy);
    }
    else if (configurationStrategy.IsServer())
    {
        return CreateServer(configurationStrategy);
    }

    return std::make_shared<NullServiceProducer>(configurationStrategy);
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceClient(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostClient(configurationStrategy);

        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceServer(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostServer(configurationStrategy);

        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateAceClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpClientServiceProducer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateAceServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpServerServiceProducer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateBoostClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpClientServiceProducer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}

Network::ServiceProducerFactory::ProducerSharedPtr Network::ServiceProducerFactory::CreateBoostServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpServerServiceProducer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceProducer>(configurationStrategy);
    }
}