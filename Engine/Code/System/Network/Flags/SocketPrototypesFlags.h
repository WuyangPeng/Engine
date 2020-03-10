// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:24)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <WinSock2.h>
#endif // SYSTEM_PLATFORM_WIN32 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32 	 

	enum class AddressFamilies
	{
		Any = -1,
		Unspec = AF_UNSPEC,
		Unix = AF_UNIX,
		Inet = AF_INET,
		Implink = AF_IMPLINK,
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
		Decnet = AF_DECnet,
		Dli = AF_DLI,
		Lat = AF_LAT,
		Hylink = AF_HYLINK,
		Appletalk = AF_APPLETALK,
		Netbios = AF_NETBIOS,
		Voiceview = AF_VOICEVIEW,
		Firefox = AF_FIREFOX,
		Unknown1 = AF_UNKNOWN1,
		Ban = AF_BAN,
		Inet6 = AF_INET6,

		Max = AF_MAX,
	};

	enum class ProtocolFamilies
	{
		Unspec = PF_UNSPEC,
		Unix = PF_UNIX,
		Inet = PF_INET,
		Implink = PF_IMPLINK,
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
		Decnet = PF_DECnet,
		Dli = PF_DLI,
		Lat = PF_LAT,
		Hylink = PF_HYLINK,
		Appletalk = PF_APPLETALK,
		Voiceview = PF_VOICEVIEW,
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
		Seqpacket = SOCK_SEQPACKET,
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
		Dontroute = MSG_DONTROUTE,
	};

	enum class IoctlSocketCmd : uint32_t
	{
		FionBio = FIONBIO,
		FionRead = FIONREAD,
		Siocatmark = SIOCATMARK,
	};

	enum class SocketLevelOption
	{
		Socket = SOL_SOCKET,
		IpprotoTcp = IPPROTO_TCP,
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
		Exclusiveaddruse = SO_EXCLUSIVEADDRUSE,
		MaxMsgSize = SO_MAX_MSG_SIZE,
		PortScalability = SO_PORT_SCALABILITY,
		ProtocolInfo = SO_PROTOCOL_INFO,

		TcpNodelay = TCP_NODELAY,
	};

	enum class ShutdownHow
	{
		Receive = SD_RECEIVE,
		Send = SD_SEND,
		Both = SD_BOTH,
	};

#else // !SYSTEM_PLATFORM_WIN32  	

	enum class AddressFamilies
	{
		Any = -1,
		Unspec = 0,
		Unix = 1,
		Inet = 2,
		Implink = 3,
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
		Decnet = 12,
		Dli = 13,
		Lat = 14,
		Hylink = 15,
		Appletalk = 16,
		Netbios = 17,
		Voiceview = 18,
		Firefox = 19,
		Unknown1 = 20,
		Ban = 21,

		Max = 22,
	};

	enum class ProtocolFamilies
	{
		Unspec = 0,
		Unix = 1,
		Inet = 2,
		Implink = 3,
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
		Decnet = 12,
		Dli = 13,
		Lat = 14,
		Hylink = 15,
		Appletalk = 16,
		Voiceview = 18,
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
		Seqpacket = 5,
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
		Dontroute = 0x4,
	};

	enum class IoctlSocketCmd : uint32_t
	{
		FionBio = FIONBIO,
		FionRead = FIONREAD,
		Siocatmark = SIOCATMARK,
	};

	enum class SocketLevelOption
	{
		Socket = 0xffff,
		IpprotoTcp = 6,
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
		Exclusiveaddruse = (~ReuseAddr),
		MaxMsgSize = 0x2003,
		PortScalability = 0x3006,
		ProtocolInfo = 0x2005,

		TcpNodelay = 0x0001,
	};

	enum class ShutdownHow
	{
		Receive = 0x00,
		Send = 0x01,
		Both = 0x02,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_NETWORK_SOCKET_PROTOTYPES_FLAGS_H
