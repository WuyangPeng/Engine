/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:20)

#ifndef NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace Network
{
    enum class WrappersStrategy
    {
        Default = 0,
        Ace = 1,
        Boost = 2,
        Beast = 3,
        Network = 4,
        ActiveMq = 5,
        Nats = 6,
        Kafka = 7,
        Null = 8,
    };

    enum class ConnectStrategy
    {
        Tcp = 0,
        Udp = 1,
        Http = 2,
        WebSocket = 3,
        Kcp = 4,
    };

    enum class WrappersSubStrategy
    {
        Default = 0,

        SendBufferSize = 1,
        ReceiveBufferSize = 2,

        Threads = 3,
        MultiContext = 4,
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
    };

    enum class MessageHeadStrategy
    {
        Default = 0,

        Encrypted = (1 << 0),
        Compression = (1 << 1),

        PrefixBegin,

        HasUserId = (1 << 2),
        HasRpcCode = (1 << 3),
        HasErrorCode = (1 << 4),
        HasSecretKey = (1 << 5),

        PrefixEnd,

        UseSubId = (1 << 6),
        UseDescribe = (1 << 7),

        UseProtoBuf = (1 << 8),
        UseJson = (1 << 9),

        End,
    };

    NODISCARD static constexpr bool IsUseSubId(const MessageHeadStrategy messageHeadStrategy) noexcept
    {
        using System::operator&;

        return (messageHeadStrategy & MessageHeadStrategy::UseSubId) != MessageHeadStrategy::Default;
    }

    NODISCARD static constexpr bool IsUseDescribe(const MessageHeadStrategy messageHeadStrategy) noexcept
    {
        using System::operator&;

        return (messageHeadStrategy & MessageHeadStrategy::UseDescribe) != MessageHeadStrategy::Default;
    }

    enum class OpenSslStrategy
    {
        Default = 0,
        OpenSsl = 1,

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
        LeaderBoardServer,
        MailServer,
        ChatServer,
        RechargeServer,
        LogServer,
        GameMasterServer,
        ServerManager,
        UpdateServer,
        BackgroundServer,
        DatabaseServer,
    };
}

#endif  // NETWORK_NETWORK_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
