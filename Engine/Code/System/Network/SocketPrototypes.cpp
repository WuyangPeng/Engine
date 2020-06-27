// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:27)

#include "System/SystemExport.h"

#include "SocketPrototypes.h"
#include "Flags/SocketPrototypesFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/NetworkMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <Ws2tcpip.h> 
#endif // SYSTEM_PLATFORM_WIN32

#include <array>

using std::array;
using std::string;

System::WinSocket System
	::GetSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::socket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(addressFamilies);
	SYSTEM_UNUSED_ARG(type);
	SYSTEM_UNUSED_ARG(protocol);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

uint16_t System
	::GetHostToNetShort(uint16_t hostShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::htons(hostShort);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hostShort);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::Bind(WinSocket winSocket, const WinSockAddrIn* address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	if (::bind(winSocket, reinterpret_cast<const WinSockAddr*>(address), sizeof(WinSockAddrIn)) != g_SocketError)
		return true;
	else
		return false;
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(address);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System
	::Accept(WinSocket winSocket, WinSockAddrIn* address, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	return ::accept(winSocket, reinterpret_cast<WinSockAddr*>(address), namelen);
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(namelen);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::Listen(WinSocket winSocket, int backlog) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::listen(winSocket, backlog) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(backlog);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseSocket(WinSocket winSocket) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::closesocket(winSocket) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::recv(winSocket, buf, len, EnumCastUnderlying(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buf);
	SYSTEM_UNUSED_ARG(len);
	SYSTEM_UNUSED_ARG(flags);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::IsSocketValid(WinSocket winSocket) noexcept
{
	if (winSocket != g_InvalidSocket)
		return true;
	else
		return false;
}

unsigned long System
	::GetHostToNetLong(unsigned long hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::htonl(hostlong);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hostlong);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::Connect(WinSocket winSocket, const WinSockAddrIn* address) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
	if (::connect(winSocket, reinterpret_cast<const WinSockAddr*>(address), sizeof(WinSockAddrIn)) != g_SocketError)
		return true;
	else
		return false;
#include STSTEM_WARNING_POP 
}

int System
	::Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::send(winSocket, buf, len, static_cast<int>(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buf);
	SYSTEM_UNUSED_ARG(len);
	SYSTEM_UNUSED_ARG(flags);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

unsigned long System
	::GetInetAddr(const char* cp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	WinSockInAddr address{};
	if (0 < inet_pton(EnumCastUnderlying(ProtocolFamilies::Inet), cp, &address))
	{
		return address.s_addr;
	}
	return 0;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(cp);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::ioctlsocket(winSocket, EnumCastUnderlying(cmd), argp) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(cmd);
	SYSTEM_UNUSED_ARG(argp);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::GetPeerName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	if (::getpeername(winSocket, reinterpret_cast<WinSockAddr*>(name), namelen) != g_SocketError)
		return true;
	else
		return false;
	#include STSTEM_WARNING_POP 

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(namelen);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::GetSockName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	if (::getsockname(winSocket, reinterpret_cast<WinSockAddr*>(name), namelen) != g_SocketError)
		return true;
	else
		return false;
	#include STSTEM_WARNING_POP 

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(namelen);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::GetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::getsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(level);
	SYSTEM_UNUSED_ARG(optName);
	SYSTEM_UNUSED_ARG(optVal);
	SYSTEM_UNUSED_ARG(optLen);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

string System
	::InetNtoa(const WinSockInAddr& in)
{
#ifdef SYSTEM_PLATFORM_WIN32	 
	const WinSockInAddr copy{ in };
	constexpr size_t stringBufSize{ 256 };
	array<char, stringBufSize> stringBuf{};
	if (inet_ntop(EnumCastUnderlying(ProtocolFamilies::Inet), &copy, stringBuf.data(), stringBufSize) != nullptr)
	{
		return stringBuf.data();
	}

	return stringBuf.data();
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(in);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::SetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::setsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(level);
	SYSTEM_UNUSED_ARG(optName);
	SYSTEM_UNUSED_ARG(optVal);
	SYSTEM_UNUSED_ARG(optLen);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

uint16_t System
	::GetNetToHostShort(uint16_t netShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::ntohs(netShort);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(netShort);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

unsigned long System
	::GetNetToHostLong(unsigned long netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::ntohl(netlong);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(netlong);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ShutDown(WinSocket winSocket, ShutdownHow how) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::shutdown(winSocket, EnumCastUnderlying(how)) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(how);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

int System
	::RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockAddrIn* from, int* fromlen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	return ::recvfrom(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<WinSockAddr*>(from), fromlen);
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buf);
	SYSTEM_UNUSED_ARG(len);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(from);
	SYSTEM_UNUSED_ARG(fromlen);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

int System
	::SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockAddrIn* to) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)
	return ::sendto(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<const WinSockAddr*>(to), sizeof(WinSockAddrIn));
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buf);
	SYSTEM_UNUSED_ARG(len);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(to);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

int System
	::Select(int width, WinSockFdSet* readfds, WinSockFdSet* writefds, WinSockFdSet* exceptfds, const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::select(width, readfds, writefds, exceptfds, timeout);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(width);
	SYSTEM_UNUSED_ARG(readfds);
	SYSTEM_UNUSED_ARG(writefds);
	SYSTEM_UNUSED_ARG(exceptfds);
	SYSTEM_UNUSED_ARG(timeout);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

void System
	::WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26446)
	#include SYSTEM_WARNING_DISABLE(26482)
	SYSTEM_FD_CLRER(winSocket, fds);
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(fds);
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::WinSockFdIsSet(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (SYSTEM_FD_IS_SET(winSocket, fds) != 0)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(fds);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

void System
	::WinSockSetFd(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26482)
	#include SYSTEM_WARNING_DISABLE(26446)
		SYSTEM_FD_SET(winSocket, fds);
	#include STSTEM_WARNING_POP 

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(fds);
#endif // SYSTEM_PLATFORM_WIN32
}
