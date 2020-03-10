// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:26)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_H

#include "System/SystemDll.h" 

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/SocketPrototypesUsing.h" 

#include <string>

namespace System
{
	bool SYSTEM_DEFAULT_DECLARE IsSocketValid(WinSocket winSocket) noexcept;
	WinSocket SYSTEM_DEFAULT_DECLARE GetSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSocket(WinSocket winSocket) noexcept;

	uint16_t SYSTEM_DEFAULT_DECLARE GetHostToNetShort(uint16_t hostShort) noexcept;
	unsigned long SYSTEM_DEFAULT_DECLARE GetHostToNetLong(unsigned long hostlong) noexcept;
	uint16_t SYSTEM_DEFAULT_DECLARE GetNetToHostShort(uint16_t netShort) noexcept;
	unsigned long SYSTEM_DEFAULT_DECLARE GetNetToHostLong(unsigned long netlong) noexcept;

	bool SYSTEM_DEFAULT_DECLARE Bind(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
	bool SYSTEM_DEFAULT_DECLARE Listen(WinSocket winSocket, int backlog) noexcept;
	WinSocket SYSTEM_DEFAULT_DECLARE Accept(WinSocket winSocket, WinSockAddrIn* address, int* namelen) noexcept;
	int SYSTEM_DEFAULT_DECLARE Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept;

	bool SYSTEM_DEFAULT_DECLARE Connect(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
	int SYSTEM_DEFAULT_DECLARE Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept;
	unsigned long SYSTEM_DEFAULT_DECLARE GetInetAddr(const char* cp) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetPeerName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSockName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
	SYSTEM_DEFAULT_DECLARE std::string InetNtoa(const WinSockInAddr& in);

	bool SYSTEM_DEFAULT_DECLARE GetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept;

	bool SYSTEM_DEFAULT_DECLARE ShutDown(WinSocket winSocket, ShutdownHow how) noexcept;
	int SYSTEM_DEFAULT_DECLARE RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockAddrIn* from, int* fromlen) noexcept;
	int SYSTEM_DEFAULT_DECLARE SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockAddrIn* to) noexcept;
	int SYSTEM_DEFAULT_DECLARE Select(int width, WinSockFdSet* readfds, WinSockFdSet* writefds, WinSockFdSet* exceptfds, const WinSockTimeval* timeout) noexcept;
	void SYSTEM_DEFAULT_DECLARE WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSockFdIsSet(WinSocket winSocket, WinSockFdSet* fds) noexcept;
	void SYSTEM_DEFAULT_DECLARE WinSockSetFd(WinSocket winSocket, WinSockFdSet* fds) noexcept;
}

#endif // SYSTEM_NETWORK_SOCKET_PROTOTYPES_H
