// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_FWD_H 
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_FWD_H  

#include "NetworkFlagsFwd.h"
#include "System/Network/Using/SocketPrototypesUsing.h"

namespace System
{ 
	bool IsSocketValid(WinSocket winSocket) noexcept;
	WinSocket GetSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept;
	uint16_t GetHostToNetShort(uint16_t hostShort) noexcept;
	unsigned long GetHostToNetLong(unsigned long hostlong) noexcept;
	bool Bind(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
	bool Listen(WinSocket winSocket, int backlog) noexcept;
	WinSocket Accept(WinSocket winSocket, WinSockAddrIn* address, int* namelen) noexcept;
	bool CloseSocket(WinSocket winSocket) noexcept;
	int Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept;
	bool Connect(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
	int Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept;
	unsigned long GetInetAddr(const char* cp) noexcept;
	bool IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept;
	bool GetPeerName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
	bool GetSockName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
	bool GetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept;
	std::string InetNtoa(const WinSockInAddr& in);
	bool SetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept;
	uint16_t GetNetToHostShort(uint16_t netShort) noexcept;
	unsigned long GetNetToHostLong(unsigned long netlong) noexcept;
	bool ShutDown(WinSocket winSocket, ShutdownHow how) noexcept;
	int RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockAddrIn* from, int* fromlen) noexcept;
	int SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockAddrIn* to) noexcept;
	int Select(int width, WinSockFdSet* readfds, WinSockFdSet* writefds, WinSockFdSet* exceptfds, const WinSockTimeval* timeout) noexcept;
	void WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept;
	bool WinSockFdIsSet(WinSocket winSocket, WinSockFdSet* fds) noexcept;
	void WinSockSetFd(WinSocket winSocket, WinSockFdSet* fds) noexcept;
}

#endif // SYSTEM_NETWORK_SOCKET_PROTOTYPES_FWD_H