///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 15:13)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/SocketPrototypesUsing.h"
#include "Using/WindowsExtensionPrototypesUsing.h"
#include "Using/WindowsSockExUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE GetWinSocket(ProtocolFamilies addressFamilies,
                                                            SocketTypes type,
                                                            SocketProtocols protocol,
                                                            SocketProtocolInfoPtr protocolInfo,
                                                            SocketGroup group,
                                                            WindowsDWord flags) noexcept;

    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE WinSocketAccept(WinSocket winSocket,
                                                               WinSockAddr* addr,
                                                               WindowsIntPtr addrlen,
                                                               WinSockConditionProc condition,
                                                               WindowsDWordPtrSizeType callbackData) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketConnect(WinSocket winSocket,
                                                           const WinSockAddr* name,
                                                           int namelen,
                                                           WinSockBufPtr callerData,
                                                           WinSockBufPtr calleeData,
                                                           QualityOfServicePtr sQualityOfService,
                                                           QualityOfServicePtr gQualityOfService) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByName(WinSocket winSocket,
                                                                 TChar* nodename,
                                                                 TChar* servicename,
                                                                 WindowsDWordPtr localAddressLength,
                                                                 WinSockAddr* localAddress,
                                                                 WindowsDWordPtr remoteAddressLength,
                                                                 WinSockAddr* remoteAddress,
                                                                 const WinSockTimeval* timeout) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketHtonl(WinSocket winSocket, unsigned long hostlong, unsigned long* netlong) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketHtons(WinSocket winSocket, unsigned short hostshort, unsigned short* netshort) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketNtohl(WinSocket winSocket, unsigned long netlong, unsigned long* hostlong) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketNtohs(WinSocket winSocket, unsigned short netshort, unsigned short* hostshort) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE WinSocketRecv(WinSocket winSocket,
                                                       WinSockBufPtr buffers,
                                                       WindowsDWord bufferCount,
                                                       WindowsDWordPtr numberOfBytesRecvd,
                                                       WindowsDWordPtr flags,
                                                       SocketOverlappedPtr overlapped,
                                                       SocketOverlappedCompletionRoutine completionRoutine) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WinSocketRecvFrom(WinSocket winSocket,
                                                           WinSockBufPtr buffers,
                                                           WindowsDWord bufferCount,
                                                           WindowsDWordPtr numberOfBytesRecvd,
                                                           WindowsDWordPtr flags,
                                                           WinSockAddr* from,
                                                           WindowsIntPtr fromlen,
                                                           SocketOverlappedPtr overlapped,
                                                           SocketOverlappedCompletionRoutine completionRoutine) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE WinSocketSend(WinSocket winSocket,
                                                       WinSockBufPtr buffers,
                                                       WindowsDWord bufferCount,
                                                       WindowsDWordPtr numberOfBytesSent,
                                                       WindowsDWord flags,
                                                       SocketOverlappedPtr overlapped,
                                                       SocketOverlappedCompletionRoutine completionRoutine) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WinSocketSendTo(WinSocket winSocket,
                                                         WinSockBufPtr buffers,
                                                         WindowsDWord bufferCount,
                                                         WindowsDWordPtr numberOfBytesSent,
                                                         WindowsDWord flags,
                                                         const WinSockAddr* to,
                                                         int tolen,
                                                         SocketOverlappedPtr overlapped,
                                                         SocketOverlappedCompletionRoutine completionRoutine) noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
