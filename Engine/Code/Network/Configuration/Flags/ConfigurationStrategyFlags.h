///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 13:34)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Network
{
    enum class WrappersStrategy
    {
        Default = 0,
        ACE = 1,
        Boost = 2,
        Network = 3,
        Socket = 4,
        Null = 5,
    };

    enum class ConnectStrategy
    {
        TCP = 0,
        UDP = 1,
        Http = 2,
        WebSocket = 3,
    };

    enum class WrappersSubStrategy
    {
        Default = 0,
        Threads = 1,
        MultiContext = 2,
    };

    enum class ServerStrategy
    {
        Disable = 0,
        Default = 1,
        Iterative = 2,
        Reactive = 3,
        Proactor = 4,
        ProcessPerConnection = 5,
        ThreadPerConnection = 6,
        RTThreadPerConnection = 7,

        End,
    };

    enum class ClientStrategy
    {
        Disable = 0,
        Default = 1,
        Cache = 2,
        OnlySending = 3,

        End,
    };

    enum class MessageStrategy
    {
        Default = 0,
        Iovec = 1,
        Fixed = 2,

        End,
    };

    enum class ParserStrategy
    {
        LittleEndian = 0,
        BigEndian = 1,

        End,
    };

    enum class EncryptedCompressionStrategy
    {
        Default = 0,
        Encrypted = (1 << 0),
        Compression = (1 << 1),
        CompressionPriority = (1 << 2),

        End,
    };

    enum class OpenSSLStrategy
    {
        Default = 0,
        OpenSSL = 1,

        End,
    };

    enum class SocketSendMessage
    {
        Default = 0,
        Immediately,  // 立即
        Cache,  // 缓存
        FrameCache,  // 帧缓存
    };

    enum class SocketType
    {
        GameClient,
        RobotClient,
        MessageClient,
        BackgroundClient,

        GatewayServer,
        LoginServer,
        GameServer,
        FightingServer,
        WorldServer,
        OfflineServer,
        LeaderboardServer,
        MailServer,
        ChatServer,
        RechargeServer,
        LogServer,
        GameMasterServer,
        ServerManager,
        UpdateServer,
        DatabaseServer,
        BackgroundServer,
    };

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(ServerStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(ServerStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(ClientStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(ClientStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(MessageStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(MessageStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(ParserStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(ParserStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(OpenSSLStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(OpenSSLStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(EncryptedCompressionStrategy);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(EncryptedCompressionStrategy);

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(SocketSendMessage);
    ENUM_RIGHT_SHIFTABLE_OPERATOR_WCHAR_DEFINE(SocketSendMessage);
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
