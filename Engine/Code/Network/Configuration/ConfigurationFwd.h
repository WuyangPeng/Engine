///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/17 13:38)

#ifndef NETWORK_NETWORK_CONFIGURATION_FWD_H
#define NETWORK_NETWORK_CONFIGURATION_FWD_H

namespace Network
{
    class ConfigurationStrategy;
    class ConfigurationSubStrategy;
    class ConfigurationParameter;
    class AnalysisNetworkConfiguration;

    enum class WrappersStrategy;
    enum class ConnectStrategy;
    enum class WrappersSubStrategy;
    enum class ServerStrategy;
    enum class ClientStrategy;
    enum class MessageStrategy;
    enum class ParserStrategy;
    enum class OpenSSLStrategy;
    enum class EncryptedCompressionStrategy;
    enum class SocketSendMessage;
    enum class SocketType;
}

#endif  // NETWORK_NETWORK_CONFIGURATION_FWD_H