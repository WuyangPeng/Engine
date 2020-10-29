//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 19:03)

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

        [[nodiscard]] static const ImplTypePtr Create();
        [[nodiscard]] static const ImplTypePtr Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ServerStrategy serverStrategy,
                                                      MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                                                      const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
                                                      SocketSendMessage socketSendMessage, const std::string& ip, int port);
        [[nodiscard]] static const ImplTypePtr Create(WrappersStrategy wrappersStrategy, ConnectStrategy connectStrategy, ClientStrategy clientStrategy,
                                                      MessageStrategy messageStrategy, ParserStrategy parserStrategy, OpenSSLStrategy openSSLStrategy,
                                                      const ConfigurationSubStrategy& subStrategy, const ConfigurationParameter& configurationParameter,
                                                      SocketSendMessage socketSendMessage, const std::string& ip, int port);
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FACTORY_H
