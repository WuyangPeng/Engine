///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 10:10)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationInternalFwd.h"

#include <memory>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConfigurationStrategyFactory final
    {
    public:
        using ClassType = ConfigurationStrategyFactory;
        using ImplType = ConfigurationStrategyImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        ConfigurationStrategyFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypePtr Create();
        NODISCARD static ImplTypePtr Create(WrappersStrategy wrappersStrategy,
                                            ConnectStrategy connectStrategy,
                                            ServerStrategy serverStrategy,
                                            MessageStrategy messageStrategy,
                                            ParserStrategy parserStrategy,
                                            OpenSSLStrategy openSSLStrategy,
                                            EncryptedCompressionStrategy encryptedCompressionStrategy,
                                            const ConfigurationSubStrategy& subStrategy,
                                            const ConfigurationParameter& configurationParameter,
                                            SocketSendMessage socketSendMessage,
                                            const std::string& host,
                                            int port);
        NODISCARD static ImplTypePtr Create(WrappersStrategy wrappersStrategy,
                                            ConnectStrategy connectStrategy,
                                            ClientStrategy clientStrategy,
                                            MessageStrategy messageStrategy,
                                            ParserStrategy parserStrategy,
                                            OpenSSLStrategy openSSLStrategy,
                                            EncryptedCompressionStrategy encryptedCompressionStrategy,
                                            const ConfigurationSubStrategy& subStrategy,
                                            const ConfigurationParameter& configurationParameter,
                                            SocketSendMessage socketSendMessage,
                                            const std::string& host,
                                            int port);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
