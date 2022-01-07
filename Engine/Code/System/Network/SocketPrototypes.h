///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:35)

#ifndef SYSTEM_NETWORK_SOCKET_PROTOTYPES_H
#define SYSTEM_NETWORK_SOCKET_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/SocketPrototypesUsing.h"

#include <string>

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSocketValid(WinSocket winSocket) noexcept;
    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE GetSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSocket(WinSocket winSocket) noexcept;

    NODISCARD uint16_t SYSTEM_DEFAULT_DECLARE GetHostToNetShort(uint16_t hostShort) noexcept;
    NODISCARD unsigned long SYSTEM_DEFAULT_DECLARE GetHostToNetLong(unsigned long hostlong) noexcept;
    NODISCARD uint16_t SYSTEM_DEFAULT_DECLARE GetNetToHostShort(uint16_t netShort) noexcept;
    NODISCARD unsigned long SYSTEM_DEFAULT_DECLARE GetNetToHostLong(unsigned long netlong) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE Bind(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE Listen(WinSocket winSocket, int backlog) noexcept;
    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE Accept(WinSocket winSocket, WinSockAddrIn* address, int* namelen) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE Recv(WinSocket winSocket, char* buf, int len, SocketRecv flags) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE Connect(WinSocket winSocket, const WinSockAddrIn* address) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE Send(WinSocket winSocket, const char* buf, int len, SocketSend flags) noexcept;
    NODISCARD unsigned long SYSTEM_DEFAULT_DECLARE GetInetAddr(const char* cp) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetPeerName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSockName(WinSocket winSocket, WinSockAddrIn* name, int* namelen) noexcept;
    NODISCARD SYSTEM_DEFAULT_DECLARE std::string InetNtoa(const WinSockInAddr& in);

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, char* optVal, int* optLen) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSockOpt(WinSocket winSocket, SocketLevelOption level, SocketRetrievedOption optName, const char* optVal, int optLen) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IoctlSocket(WinSocket winSocket, IoctlSocketCmd cmd, unsigned long* argp) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ShutDown(WinSocket winSocket, ShutdownHow how) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE RecvFrom(WinSocket winSocket, char* buf, int len, SocketRecv flags, WinSockAddrIn* from, int* fromlen) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE SendTo(WinSocket winSocket, const char* buf, int len, SocketSend flags, const WinSockAddrIn* to) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE Select(int width, WinSockFdSet* readfds, WinSockFdSet* writefds, WinSockFdSet* exceptfds, const WinSockTimeval* timeout) noexcept;
    void SYSTEM_DEFAULT_DECLARE WinSockFdClear(WinSocket winSocket, WinSockFdSet* fds) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSockFdIsSet(WinSocket winSocket, WinSockFdSet* fds) noexcept;
    void SYSTEM_DEFAULT_DECLARE WinSockSetFd(WinSocket winSocket, WinSockFdSet* fds) noexcept;
}

#endif  // SYSTEM_NETWORK_SOCKET_PROTOTYPES_H
