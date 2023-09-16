///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/14 14:08)

#include "Network/NetworkExport.h"

#include "NullSession.h"
#include "SessionFactory.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/AceWrappers/Detail/Service/AceTcpClientSession.h"
#include "Network/AceWrappers/Detail/Service/AceTcpServerSession.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpClientSession.h"
#include "Network/BoostWrappers/Detail/Service/BoostTcpServerSession.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SessionFactory)

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    if (configurationStrategy.IsClient())
    {
        return CreateClient(configurationStrategy);
    }
    else if (configurationStrategy.IsServer())
    {
        return CreateServer(configurationStrategy);
    }

    return std::make_shared<NullSession>(configurationStrategy);
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceClient(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostClient(configurationStrategy);

        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::Ace:
            return CreateAceServer(configurationStrategy);

        case WrappersStrategy::Default:
        case WrappersStrategy::Boost:
            return CreateBoostServer(configurationStrategy);

        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateAceClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpClientSession>(configurationStrategy);
        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateAceServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<AceTcpServerSession>(configurationStrategy);
        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateBoostClient(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpClientSession>(configurationStrategy);
        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}

Network::SessionFactory::SessionSharedPtr Network::SessionFactory::CreateBoostServer(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetConnectStrategy())
    {
        case ConnectStrategy::Tcp:
            return std::make_shared<BoostTcpServerSession>(configurationStrategy);
        default:
            return std::make_shared<NullSession>(configurationStrategy);
    }
}
