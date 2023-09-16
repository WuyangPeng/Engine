///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:23)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <WinSock2.h>

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
        Datakit = AF_DATAKIT,
        Ccitt = AF_CCITT,
        Sna = AF_SNA,
        DeCnet = AF_DECnet,
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
        Datakit = PF_DATAKIT,
        Ccitt = PF_CCITT,
        Sna = PF_SNA,
        DeCnet = PF_DECnet,
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

    enum class SocketRecv
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
        DontRoute = MSG_DONTROUTE,
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
        ReuseAddr = SO_REUSEADDR,
        KeepAlive = SO_KEEPALIVE,
        DontRoute = SO_DONTROUTE,
        Broadcast = SO_BROADCAST,
        UseLoopBack = SO_USELOOPBACK,
        Linger = SO_LINGER,
        OobinLine = SO_OOBINLINE,

        DontLinger = SO_DONTLINGER,

        SndBuf = SO_SNDBUF,
        RcvBuf = SO_RCVBUF,
        Sndlowat = SO_SNDLOWAT,
        Rcvlowat = SO_RCVLOWAT,
        Sndtimeo = SO_SNDTIMEO,
        Rcvtimeo = SO_RCVTIMEO,
        Error = SO_ERROR,
        Type = SO_TYPE,

        BspState = SO_BSP_STATE,
        ConditionalAccept = SO_CONDITIONAL_ACCEPT,
        ExclusiveAddrUse = SO_EXCLUSIVEADDRUSE,
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
        Datakit = 9,
        Ccitt = 10,
        Sna = 11,
        DeCnet = 12,
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
        Datakit = 9,
        Ccitt = 10,
        Sna = 11,
        DeCnet = 12,
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

    enum class SocketRecv
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
        DontRoute = 0x4,
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
        ReuseAddr = 0x0004,
        KeepAlive = 0x0008,
        DontRoute = 0x0010,
        Broadcast = 0x0020,
        UseLoopBack = 0x0040,
        Linger = 0x0080,
        OobinLine = 0x0100,

        DontLinger = (~Linger),

        SndBuf = 0x1001,
        RcvBuf = 0x1002,
        Sndlowat = 0x1003,
        Rcvlowat = 0x1004,
        Sndtimeo = 0x1005,
        Rcvtimeo = 0x1006,
        Error = 0x1007,
        Type = 0x1008,

        BspState = 0x1009,
        ConditionalAccept = 0x3002,
        ExclusiveAddrUse = (~ReuseAddr),
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
        FionBio = FIONBIO,
        FionRead = FIONREAD,
        Siocatmark = SIOCATMARK,
    };
}

#endif  // SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
