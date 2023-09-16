///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:47)

#include "System/SystemExport.h"

#include "SocketPrototypes.h"
#include "Flags/SocketPrototypesFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/NetworkMacro.h"
#include "System/Helper/PragmaWarning.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <Ws2tcpip.h>

#endif  // SYSTEM_PLATFORM_WIN32

#include <array>

namespace System
{
    NODISCARD const WinSockAddress* ToWinSockAddress(const WinSockInternetAddress* address) noexcept
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<const WinSockAddress*>(address);

#include SYSTEM_WARNING_POP
    }

    NODISCARD WinSockAddress* ToWinSockAddress(WinSockInternetAddress* address) noexcept
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<WinSockAddress*>(address);

#include SYSTEM_WARNING_POP
    }
}

System::WinSocket System::CreateSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::socket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(addressFamilies, type, protocol);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::CreateTcpSocket() noexcept
{
    return CreateSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
}

System::WinSocket System::CreateUdpSocket() noexcept
{
    return CreateSocket(ProtocolFamilies::Inet, SocketTypes::Dgram, SocketProtocols::Udp);
}

uint16_t System::GetHostToNetShort(uint16_t hostShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::htons(hostShort);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hostShort);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Bind(WinSocket winSocket, const WinSockInternetAddress* address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::bind(winSocket, ToWinSockAddress(address), sizeof(WinSockInternetAddress)) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::Accept(WinSocket winSocket, WinSockInternetAddress* address, int* nameLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::accept(winSocket, ToWinSockAddress(address), nameLen);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, address, nameLen);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Listen(WinSocket winSocket, int backlog) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::listen(winSocket, backlog) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, backlog);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSocket(WinSocket winSocket) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::closesocket(winSocket) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::recv(winSocket, buf, len, EnumCastUnderlying(flags));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buf, len, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSocketValid(WinSocket winSocket) noexcept
{
    if (winSocket != invalidSocket)
        return true;
    else
        return false;
}

unsigned long System::GetHostToNetLong(unsigned long hostLong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::htonl(hostLong);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hostLong);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Connect(WinSocket winSocket, const WinSockInternetAddress* address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::connect(winSocket, ToWinSockAddress(address), sizeof(WinSockInternetAddress)) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::send(winSocket, buf, len, EnumCastUnderlying(flags));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buf, len, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetInternetAddress(const char* cp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    InternetAddress address{};
    if (0 < inet_pton(EnumCastUnderlying(ProtocolFamilies::Inet), cp, &address))
    {
        return address.s_addr;
    }
    return 0;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(cp);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ioctlsocket(winSocket, EnumCastUnderlying(cmd), argp) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, cmd, argp);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetPeerName(WinSocket winSocket, WinSockInternetAddress* name, int* nameLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::getpeername(winSocket, ToWinSockAddress(name), nameLen) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, name, nameLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockName(WinSocket winSocket, WinSockInternetAddress* name, int* nameLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::getsockname(winSocket, ToWinSockAddress(name), nameLen) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, name, nameLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockOption(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::getsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, level, optName, optVal, optLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

std::string System::InetNtoa(const InternetAddress& in)
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto stringBufSize = 256u;
    std::array<char, stringBufSize> stringBuf{};
    if (inet_ntop(EnumCastUnderlying(ProtocolFamilies::Inet), &in, stringBuf.data(), stringBuf.size()) != nullptr)
    {
        return stringBuf.data();
    }

    return "";

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(in);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSockOption(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::setsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, level, optName, optVal, optLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

uint16_t System::GetNetToHostShort(uint16_t netShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ntohs(netShort);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(netShort);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetNetToHostLong(unsigned long netLong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ntohl(netLong);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(netLong);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ShutDown(WinSocket winSocket, ShutdownHow how) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::shutdown(winSocket, EnumCastUnderlying(how)) != socketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, how);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockInternetAddress* from, int* fromLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::recvfrom(winSocket, buf, len, EnumCastUnderlying(flags), ToWinSockAddress(from), fromLen);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buf, len, flags, from, fromLen);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockInternetAddress* to) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::sendto(winSocket, buf, len, EnumCastUnderlying(flags), ToWinSockAddress(to), sizeof(WinSockInternetAddress));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buf, len, flags, to);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Select(int width, WinSockFdSet* readFds, WinSockFdSet* writeFds, WinSockFdSet* exceptFds, const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::select(width, readFds, writeFds, exceptFds, timeout);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(width, readFds, writeFds, exceptFds, timeout);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    SYSTEM_FD_CLEAR(winSocket, fds);

#include SYSTEM_WARNING_POP
}

bool System::WinSockFdIsSet(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
    if (SYSTEM_FD_IS_SET(winSocket, fds) != 0)
        return true;
    else
        return false;
}

void System::WinSockSetFd(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)

    SYSTEM_FD_SET(winSocket, fds);

#include SYSTEM_WARNING_POP
}
