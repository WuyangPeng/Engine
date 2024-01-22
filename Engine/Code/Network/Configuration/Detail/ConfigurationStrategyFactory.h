/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:21)

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
                                            OpenSslStrategy openSslStrategy,
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
                                            OpenSslStrategy openSslStrategy,
                                            EncryptedCompressionStrategy encryptedCompressionStrategy,
                                            const ConfigurationSubStrategy& subStrategy,
                                            const ConfigurationParameter& configurationParameter,
                                            SocketSendMessage socketSendMessage,
                                            const std::string& host,
                                            int port);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
