/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 20:21)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

#elif defined(SYSTEM_PLATFORM_LINUX)

    #include <sys/ioctl.h>
    #include <sys/socket.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class AddressFamilies
    {
        Any = -1,
        UnSpec = AF_UNSPEC,
        Unix = AF_UNIX,
        Internet = AF_INET,
        ImpLink = AF_IMPLINK,
        Pup = AF_PUP,
        Chaos = AF_CHAOS,
        Ipx = AF_IPX,
        Ns = AF_NS,
        Iso = AF_ISO,
        Osi = AF_OSI,
        Ecma = AF_ECMA,
        DataKit = AF_DATAKIT,
        Ccitt = AF_CCITT,
        Sna = AF_SNA,
        DecNet = AF_DECnet,
        Dli = AF_DLI,
        Lat = AF_LAT,
        HyLink = AF_HYLINK,
        AppleTalk = AF_APPLETALK,
        NetBios = AF_NETBIOS,
        VoiceView = AF_VOICEVIEW,
        Firefox = AF_FIREFOX,
        Unknown1 = AF_UNKNOWN1,
        Ban = AF_BAN,
        Inet6 = AF_INET6,

        Max = AF_MAX,
    };

    enum class ProtocolFamilies
    {
        UnSpec = PF_UNSPEC,
        Unix = PF_UNIX,
        Inet = PF_INET,
        ImpLink = PF_IMPLINK,
        Pup = PF_PUP,
        Chaos = PF_CHAOS,
        Ipx = PF_IPX,
        Ns = PF_NS,
        Iso = PF_ISO,
        Osi = PF_OSI,
        Ecma = PF_ECMA,
        DataKit = PF_DATAKIT,
        Ccitt = PF_CCITT,
        Sna = PF_SNA,
        DecNet = PF_DECnet,
        Dli = PF_DLI,
        Lat = PF_LAT,
        HyLink = PF_HYLINK,
        AppleTalk = PF_APPLETALK,
        VoiceView = PF_VOICEVIEW,
        Firefox = PF_FIREFOX,
        Unknown1 = PF_UNKNOWN1,
        Ban = PF_BAN,
        Inet6 = PF_INET6,

        Max = PF_MAX,
    };

    enum class SocketTypes
    {
        Stream = SOCK_STREAM,
        Dgram = SOCK_DGRAM,
        Raw = SOCK_RAW,
        Rdm = SOCK_RDM,
        SeqPacket = SOCK_SEQPACKET,
    };

    enum class SocketProtocols
    {
        Ip = IPPROTO_IP,
        Icmp = IPPROTO_ICMP,
        Igmp = IPPROTO_IGMP,
        Ggp = IPPROTO_GGP,
        Tcp = IPPROTO_TCP,
        Pup = IPPROTO_PUP,
        Udp = IPPROTO_UDP,
        Idp = IPPROTO_IDP,
        Nd = IPPROTO_ND,

        Raw = IPPROTO_RAW,
        Max = IPPROTO_MAX,
    };

    enum class SocketReceive
    {
        Default = 0x0,
        Oob = MSG_OOB,
        Peek = MSG_PEEK,
        WaitAll = MSG_WAITALL,
    };

    enum class SocketSend
    {
        Default = 0x0,
        Oob = MSG_OOB,
        DoNotRoute = MSG_DONTROUTE,
    };

    enum class SocketLevelOption
    {
        Socket = SOL_SOCKET,
        IpProtoTcp = IPPROTO_TCP,
    };

    enum class SocketRetrievedOption
    {
        Debug = SO_DEBUG,
        AcceptConn = SO_ACCEPTCONN,
        ReuseAddress = SO_REUSEADDR,
        KeepAlive = SO_KEEPALIVE,
        DoNotRoute = SO_DONTROUTE,
        Broadcast = SO_BROADCAST,
        UseLoopBack = SO_USELOOPBACK,
        Linger = SO_LINGER,
        OobInLine = SO_OOBINLINE,

        DoNotLinger = SO_DONTLINGER,

        SndBuf = SO_SNDBUF,
        RcvBuf = SO_RCVBUF,
        SendLowWater = SO_SNDLOWAT,
        ReceiveLowWater = SO_RCVLOWAT,
        SendTimeout = SO_SNDTIMEO,
        ReceiveTimeout = SO_RCVTIMEO,
        Error = SO_ERROR,
        Type = SO_TYPE,

        BspState = SO_BSP_STATE,
        ConditionalAccept = SO_CONDITIONAL_ACCEPT,
        ExclusiveAddressUse = SO_EXCLUSIVEADDRUSE,
        MaxMsgSize = SO_MAX_MSG_SIZE,
        PortScalability = SO_PORT_SCALABILITY,
        ProtocolInfo = SO_PROTOCOL_INFO,

        TcpNoDelay = TCP_NODELAY,
    };

    enum class ShutdownHow
    {
        Receive = SD_RECEIVE,
        Send = SD_SEND,
        Both = SD_BOTH,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class AddressFamilies
    {
        Any = -1,
        UnSpec = 0,
        Unix = 1,
        Internet = 2,
        ImpLink = 3,
        Pup = 4,
        Chaos = 5,
        Ipx = 6,
        Ns = 6,
        Iso = 7,
        Osi = Iso,
        Ecma = 8,
        DataKit = 9,
        Ccitt = 10,
        Sna = 11,
        DecNet = 12,
        Dli = 13,
        Lat = 14,
        HyLink = 15,
        AppleTalk = 16,
        NetBios = 17,
        VoiceView = 18,
        Firefox = 19,
        Unknown1 = 20,
        Ban = 21,

        Max = 22,
    };

    enum class ProtocolFamilies
    {
        UnSpec = 0,
        Unix = 1,
        Inet = 2,
        ImpLink = 3,
        Pup = 4,
        Chaos = 5,
        Ipx = 6,
        Ns = 6,
        Iso = 7,
        Osi = Iso,
        Ecma = 8,
        DataKit = 9,
        Ccitt = 10,
        Sna = 11,
        DecNet = 12,
        Dli = 13,
        Lat = 14,
        HyLink = 15,
        AppleTalk = 16,
        VoiceView = 18,
        Firefox = 19,
        Unknown1 = 20,
        Ban = 21,

        Max = 22,
    };

    enum class SocketTypes
    {
        Stream = 1,
        Dgram = 2,
        Raw = 3,
        Rdm = 4,
        SeqPacket = 5,
    };

    enum class SocketProtocols
    {
        Ip = 0,
        Icmp = 1,
        Igmp = 2,
        Ggp = 3,
        Tcp = 6,
        Pup = 12,
        Udp = 17,
        Idp = 22,
        Nd = 77,

        Raw = 255,
        Max = 256,
    };

    enum class SocketReceive
    {
        Default = 0x0,
        Oob = 0x1,
        Peek = 0x2,
        WaitAll = 0x8,
    };

    enum class SocketSend
    {
        Default = 0x0,
        Oob = 0x1,
        DoNotRoute = 0x4,
    };

    enum class SocketLevelOption
    {
        Socket = 0xffff,
        IpProtoTcp = 6,
    };

    enum class SocketRetrievedOption
    {
        Debug = 0x0001,
        AcceptConn = 0x0002,
        ReuseAddress = 0x0004,
        KeepAlive = 0x0008,
        DoNotRoute = 0x0010,
        Broadcast = 0x0020,
        UseLoopBack = 0x0040,
        Linger = 0x0080,
        OobInLine = 0x0100,

        DoNotLinger = (~Linger),

        SndBuf = 0x1001,
        RcvBuf = 0x1002,
        SendLowWater = 0x1003,
        ReceiveLowWater = 0x1004,
        SendTimeout = 0x1005,
        ReceiveTimeout = 0x1006,
        Error = 0x1007,
        Type = 0x1008,

        BspState = 0x1009,
        ConditionalAccept = 0x3002,
        ExclusiveAddressUse = (~ReuseAddress),
        MaxMsgSize = 0x2003,
        PortScalability = 0x3006,
        ProtocolInfo = 0x2005,

        TcpNoDelay = 0x0001,
    };

    enum class ShutdownHow
    {
        Receive = 0x00,
        Send = 0x01,
        Both = 0x02,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    enum class IoctlSocketCmd : uint32_t
    {
        FIonBlockingIO = FIONBIO,
        FIonRead = FIONREAD,
        SocketIOControlsAtMark = SIOCATMARK,
    };
}

#endif  // SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
