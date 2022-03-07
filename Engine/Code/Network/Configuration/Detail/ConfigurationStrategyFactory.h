///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 11:50)

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

        NODISCARD static const ImplTypePtr Create();
        NODISCARD static const ImplTypePtr Create(WrappersStrategy wrappersStrategy,
                                                  ConnectStrategy connectStrategy,
                                                  ServerStrategy serverStrategy,
                                                  MessageStrategy messageStrategy,
                                                  ParserStrategy parserStrategy,
                                                  OpenSSLStrategy openSSLStrategy,
                                                  EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                  const ConfigurationSubStrategy& subStrategy,
                                                  const ConfigurationParameter& configurationParameter,
                                                  SocketSendMessage socketSendMessage,
                                                  const std::string& ip,
                                                  int port);
        NODISCARD static const ImplTypePtr Create(WrappersStrategy wrappersStrategy,
                                                  ConnectStrategy connectStrategy,
                                                  ClientStrategy clientStrategy,
                                                  MessageStrategy messageStrategy,
                                                  ParserStrategy parserStrategy,
                                                  OpenSSLStrategy openSSLStrategy,
                                                  EncryptedCompressionStrategy encryptedCompressionStrategy,
                                                  const ConfigurationSubStrategy& subStrategy,
                                                  const ConfigurationParameter& configurationParameter,
                                                  SocketSendMessage socketSendMessage,
                                                  const std::string& ip,
                                                  int port);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
