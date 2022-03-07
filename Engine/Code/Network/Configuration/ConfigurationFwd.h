///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:38)

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