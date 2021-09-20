///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.4 (2021/06/04 14:55)

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

using std::array;
using std::string;

System::WinSocket System::GetSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::socket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ProtocolFamilies, SocketTypes, SocketProtocols>(addressFamilies, type, protocol);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

uint16_t System::GetHostToNetShort(uint16_t hostShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::htons(hostShort);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<uint16_t>(hostShort);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Bind(WinSocket winSocket, const WinSockAddrIn* address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    if (::bind(winSocket, reinterpret_cast<const WinSockAddr*>(address), sizeof(WinSockAddrIn)) != g_SocketError)
        return true;
    else
        return false;
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, const WinSockAddrIn*>(winSocket, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::Accept(WinSocket winSocket, WinSockAddrIn* address, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    return ::accept(winSocket, reinterpret_cast<WinSockAddr*>(address), namelen);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, WinSockAddrIn*, int*>(winSocket, address, namelen);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Listen(WinSocket winSocket, int backlog) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::listen(winSocket, backlog) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, int>(winSocket, backlog);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSocket(WinSocket winSocket) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::closesocket(winSocket) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket>(winSocket);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::recv(winSocket, buf, len, EnumCastUnderlying(flags));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, char*, int, SocketRecv>(winSocket, buf, len, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSocketValid(WinSocket winSocket) noexcept
{
    if (winSocket != g_InvalidSocket)
        return true;
    else
        return false;
}

unsigned long System::GetHostToNetLong(unsigned long hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::htonl(hostlong);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<unsigned long>(hostlong);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Connect(WinSocket winSocket, const WinSockAddrIn* address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    if (::connect(winSocket, reinterpret_cast<const WinSockAddr*>(address), sizeof(WinSockAddrIn)) != g_SocketError)
        return true;
    else
        return false;

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, const WinSockAddrIn*>(winSocket, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::send(winSocket, buf, len, EnumCastUnderlying(flags));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, const char*, int, SocketSend>(winSocket, buf, len, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetInetAddr(const char* cp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WinSockInAddr address{};
    if (0 < inet_pton(EnumCastUnderlying(ProtocolFamilies::Inet), cp, &address))
    {
        return address.s_addr;
    }
    return 0;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const char*>(cp);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ioctlsocket(winSocket, EnumCastUnderlying(cmd), argp) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, IoctlSocketCmd, unsigned long*>(winSocket, cmd, argp);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetPeerName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    if (::getpeername(winSocket, reinterpret_cast<WinSockAddr*>(name), namelen) != g_SocketError)
        return true;
    else
        return false;

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, WinSockAddrIn*, int*>(winSocket, name, namelen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    if (::getsockname(winSocket, reinterpret_cast<WinSockAddr*>(name), namelen) != g_SocketError)
        return true;
    else
        return false;

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, WinSockAddrIn*, int*>(winSocket, name, namelen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::getsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, SocketLevelOption, SocketRetrievedOption, char*, int*>(winSocket, level, optName, optVal, optLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

string System::InetNtoa(const WinSockInAddr& in)
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto stringBufSize = 256u;
    array<char, stringBufSize> stringBuf{};
    if (inet_ntop(EnumCastUnderlying(ProtocolFamilies::Inet), &in, stringBuf.data(), stringBuf.size()) != nullptr)
    {
        return stringBuf.data();
    }

    return "";

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSockInAddr>(in);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::setsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, SocketLevelOption, SocketRetrievedOption, const char*, int*>(winSocket, level, optName, optVal, optLen);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

uint16_t System::GetNetToHostShort(uint16_t netShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ntohs(netShort);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<uint16_t>(netShort);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetNetToHostLong(unsigned long netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ntohl(netlong);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<unsigned long>(netlong);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ShutDown(WinSocket winSocket, ShutdownHow how) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::shutdown(winSocket, EnumCastUnderlying(how)) != g_SocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, ShutdownHow>(winSocket, how);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockAddrIn* from, int* fromlen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::recvfrom(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<WinSockAddr*>(from), fromlen);

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, char*, int, SocketRecv, WinSockAddrIn*, int*>(winSocket, buf, len, flags, from, fromlen);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockAddrIn* to) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    return ::sendto(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<const WinSockAddr*>(to), sizeof(WinSockAddrIn));

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WinSocket, const char*, int, SocketSend, const WinSockAddrIn*>(winSocket, buf, len, flags, to);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Select(int width, WinSockFdSet* readfds, WinSockFdSet* writefds, WinSockFdSet* exceptfds, const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::select(width, readfds, writefds, exceptfds, timeout);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<int, WinSockFdSet*, WinSockFdSet*, WinSockFdSet*, const WinSockTimeval*>(width, readfds, writefds, exceptfds, timeout);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    SYSTEM_FD_CLRER(winSocket, fds);

#include STSTEM_WARNING_POP
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)

    SYSTEM_FD_SET(winSocket, fds);

#include STSTEM_WARNING_POP
}
