/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:56)

#include "Network/NetworkExport.h"

#include "NullServiceSession.h"
#include "ServiceSessionFactory.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/AceWrappers/Detail/Service/AceTcpClientServiceSession.h"
#include "Network/AceWrappers/Detail/Service/AceTcpServerServiceSession.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpClientServiceSession.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpServerServiceSession.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceSessionFactory)

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    if (configurationStrategy.IsClient())
    {
        return CreateClient(configurationStrategy);
    }
    else if (configurationStrategy.IsServer())
    {
        return CreateServer(configurationStrategy);
    }

    return std::make_shared<NullServiceSession>(configurationStrategy);
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceClient(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostClient(configurationStrategy);

        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceServer(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostServer(configurationStrategy);

        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateAceClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpClientServiceSession>(configurationStrategy);
        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateAceServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpServerServiceSession>(configurationStrategy);
        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateBoostClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpClientServiceSession>(configurationStrategy);
        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}

Network::ServiceSessionFactory::SessionSharedPtr Network::ServiceSessionFactory::CreateBoostServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpServerServiceSession>(configurationStrategy);
        default:
            return std::make_shared<NullServiceSession>(configurationStrategy);
    }
}
