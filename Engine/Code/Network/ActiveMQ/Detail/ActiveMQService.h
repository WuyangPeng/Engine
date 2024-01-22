/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:27)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SERVICE_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SERVICE_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/ActiveMQ.h"
#include "Network/Configuration/ConfigurationStrategy.h"

#ifdef NETWORK_USE_ACTIVE_MQ

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ActiveMQService final
    {
    public:
        using ClassType = ActiveMQService;

        using ConnectionSharedPtr = std::shared_ptr<cms::Connection>;

    public:
        explicit ActiveMQService(ConfigurationStrategy configurationStrategy);
        ~ActiveMQService() noexcept;
        ActiveMQService(const ActiveMQService& rhs) = delete;
        ActiveMQService& operator=(const ActiveMQService& rhs) = delete;
        ActiveMQService(ActiveMQService&& rhs) noexcept = delete;
        ActiveMQService& operator=(ActiveMQService&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConnectionSharedPtr GetConnection() noexcept;
        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD std::string GetMQConnectionUrl() const;

    private:
        using ActiveMQConnectionFactory = activemq::core::ActiveMQConnectionFactory;
        using ConnectionUniquePtr = std::unique_ptr<cms::Connection>;

    private:
        NODISCARD static std::string GetMQConnectionUrl(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static std::string GetAccount(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static std::string GetPassword(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ConnectionUniquePtr GetConnection(ActiveMQConnectionFactory& activeMQConnectionFactory, const ConfigurationStrategy& configurationStrategy);
        void Close();

    private:
        std::string mqConnectionUrl;
        ActiveMQConnectionFactory activeMQConnectionFactory;
        ConnectionSharedPtr connection;
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_SERVICE_H
