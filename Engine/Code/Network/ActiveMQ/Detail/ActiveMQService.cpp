///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 16:38)

#include "Network/NetworkExport.h"

#include "ActiveMQService.h"
#include "System/Helper/Tools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"

#ifdef NETWORK_USE_ACTIVE_MQ

Network::ActiveMQService::ActiveMQService(ConfigurationStrategy configurationStrategy)
    : mqConnectionUrl{ GetMQConnectionUrl(configurationStrategy) },
      activeMQConnectionFactory{ mqConnectionUrl },
      connection{ GetConnection(activeMQConnectionFactory, configurationStrategy) },
      configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ActiveMQService::~ActiveMQService() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Close();
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_STUB_DEFINE(Network, ActiveMQService)

Network::ActiveMQService::ConnectionSharedPtr Network::ActiveMQService::GetConnection() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return connection;
}

Network::ConfigurationStrategy Network::ActiveMQService::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

std::string Network::ActiveMQService::GetMQConnectionUrl() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return mqConnectionUrl;
}

void Network::ActiveMQService::Close()
{
    NETWORK_CLASS_IS_VALID_9;

    connection->close();
}

std::string Network::ActiveMQService::GetMQConnectionUrl(const ConfigurationStrategy& configurationStrategy)
{
    return "tcp://" + configurationStrategy.GetHost() + ":" + std::to_string(configurationStrategy.GetPort());
}

std::string Network::ActiveMQService::GetAccount(const ConfigurationStrategy& configurationStrategy)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(configurationStrategy.GetConfigurationParameter().GetFirstParameter(SYSTEM_TEXT("Account")));
}

std::string Network::ActiveMQService::GetPassword(const ConfigurationStrategy& configurationStrategy)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(configurationStrategy.GetConfigurationParameter().GetFirstParameter(SYSTEM_TEXT("Password")));
}

Network::ActiveMQService::ConnectionUniquePtr Network::ActiveMQService::GetConnection(ActiveMQConnectionFactory& activeMQConnectionFactory, const ConfigurationStrategy& configurationStrategy)
{
    if (!activeMQConnectionFactory.isUseAsyncSend())
    {
        activeMQConnectionFactory.setUseAsyncSend(true);
    }

    ConnectionUniquePtr connection{ activeMQConnectionFactory.createConnection(GetAccount(configurationStrategy), GetPassword(configurationStrategy)) };
    connection->start();

    return connection;
}

#endif  // NETWORK_USE_ACTIVE_MQ
