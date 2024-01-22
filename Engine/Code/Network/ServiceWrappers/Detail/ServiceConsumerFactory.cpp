/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:57)

#include "Network/NetworkExport.h"

#include "NullServiceConsumer.h"
#include "ServiceConsumerFactory.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Service/AceTcpClientServiceConsumer.h"
#include "Network/ACEWrappers/Detail/Service/AceTcpServerServiceConsumer.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpClientServiceConsumer.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpServerServiceConsumer.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceConsumerFactory)

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    if (configurationStrategy.IsClient())
    {
        return CreateClient(configurationStrategy);
    }
    else if (configurationStrategy.IsServer())
    {
        return CreateServer(configurationStrategy);
    }

    return std::make_shared<NullServiceConsumer>(configurationStrategy);
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceClient(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostClient(configurationStrategy);

        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceServer(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostServer(configurationStrategy);

        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateAceClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpClientServiceConsumer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateAceServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpServerServiceConsumer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateBoostClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpClientServiceConsumer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}

Network::ServiceConsumerFactory::ConsumerSharedPtr Network::ServiceConsumerFactory::CreateBoostServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpServerServiceConsumer>(configurationStrategy);
        default:
            return std::make_shared<NullServiceConsumer>(configurationStrategy);
    }
}
