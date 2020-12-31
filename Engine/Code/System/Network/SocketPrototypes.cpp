//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:07)

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

System::WinSocket System::GetSocket([[maybe_unused]] ProtocolFamilies addressFamilies, [[maybe_unused]] SocketTypes type, [[maybe_unused]] SocketProtocols protocol) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::socket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

uint16_t System::GetHostToNetShort([[maybe_unused]] uint16_t hostShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::htons(hostShort);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Bind([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] const WinSockAddrIn* address) noexcept
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::Accept([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockAddrIn* address, [[maybe_unused]] int* namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    return ::accept(winSocket, reinterpret_cast<WinSockAddr*>(address), namelen);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Listen([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] int backlog) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::listen(winSocket, backlog) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSocket([[maybe_unused]] WinSocket winSocket) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::closesocket(winSocket) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Recv([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] char* buf, [[maybe_unused]] int len, [[maybe_unused]] SocketRecv flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::recv(winSocket, buf, len, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32
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

unsigned long System::GetHostToNetLong([[maybe_unused]] unsigned long hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::htonl(hostlong);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::Connect([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] const WinSockAddrIn* address) noexcept
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Send([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] const char* buf, [[maybe_unused]] int len, [[maybe_unused]] SocketSend flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::send(winSocket, buf, len, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetInetAddr([[maybe_unused]] const char* cp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WinSockInAddr address{};
    if (0 < inet_pton(EnumCastUnderlying(ProtocolFamilies::Inet), cp, &address))
    {
        return address.s_addr;
    }
    return 0;
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IoctlSocket([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] IoctlSocketCmd cmd, [[maybe_unused]] unsigned long* argp) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ioctlsocket(winSocket, EnumCastUnderlying(cmd), argp) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetPeerName([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockAddrIn* name, [[maybe_unused]] int* namelen) noexcept
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockName([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockAddrIn* name, [[maybe_unused]] int* namelen) noexcept
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSockOpt([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] SocketLevelOption level, [[maybe_unused]] SocketRetrievedOption optName, [[maybe_unused]] char* optVal, [[maybe_unused]] int* optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::getsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

string System::InetNtoa([[maybe_unused]] const WinSockInAddr& in)
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
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSockOpt([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] SocketLevelOption level, [[maybe_unused]] SocketRetrievedOption optName, [[maybe_unused]] const char* optVal, [[maybe_unused]] int optLen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::setsockopt(winSocket, EnumCastUnderlying(level), EnumCastUnderlying(optName), optVal, optLen) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

uint16_t System::GetNetToHostShort([[maybe_unused]] uint16_t netShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ntohs(netShort);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

unsigned long System::GetNetToHostLong([[maybe_unused]] unsigned long netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ntohl(netlong);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ShutDown([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] ShutdownHow how) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::shutdown(winSocket, EnumCastUnderlying(how)) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::RecvFrom([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] char* buf, [[maybe_unused]] int len, [[maybe_unused]] SocketRecv flags, [[maybe_unused]] WinSockAddrIn* from, [[maybe_unused]] int* fromlen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    return ::recvfrom(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<WinSockAddr*>(from), fromlen);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::SendTo([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] const char* buf, [[maybe_unused]] int len, [[maybe_unused]] SocketSend flags, [[maybe_unused]] const WinSockAddrIn* to) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)
    return ::sendto(winSocket, buf, len, EnumCastUnderlying(flags), reinterpret_cast<const WinSockAddr*>(to), sizeof(WinSockAddrIn));
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::Select([[maybe_unused]] int width, [[maybe_unused]] WinSockFdSet* readfds, [[maybe_unused]] WinSockFdSet* writefds, [[maybe_unused]] WinSockFdSet* exceptfds, [[maybe_unused]] const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::select(width, readfds, writefds, exceptfds, timeout);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WinSockFdClear([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26482)
    SYSTEM_FD_CLRER(winSocket, fds);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSockFdIsSet([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (SYSTEM_FD_IS_SET(winSocket, fds) != 0)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WinSockSetFd([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockFdSet* fds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26482)
    #include SYSTEM_WARNING_DISABLE(26446)
    SYSTEM_FD_SET(winSocket, fds);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}
