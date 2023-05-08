///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/27 17:12)

#ifndef NETWORK_NETWORK_CONFIGURATION_FWD_H
#define NETWORK_NETWORK_CONFIGURATION_FWD_H

namespace Network
{
    enum class WrappersStrategy;
    enum class ConnectStrategy;
    enum class WrappersSubStrategy;
    enum class ServerStrategy;
    enum class ClientStrategy;
    enum class MessageStrategy;
    enum class ParserStrategy;
    enum class OpenSSLStrategy;
    enum class EncryptedCompressionStrategy;
    enum class MessageHeadStrategy;
    enum class SocketSendMessage;
    enum class SocketType;

    class AnalysisNetworkConfiguration;
    class ConfigurationParameter;
    class ConfigurationStrategy;
    class ConfigurationSubStrategy;

}

#endif  // NETWORK_NETWORK_CONFIGURATION_FWD_H