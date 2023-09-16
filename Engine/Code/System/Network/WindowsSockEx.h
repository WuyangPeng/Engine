///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:44)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/SocketPrototypesUsing.h"
#include "Using/WindowsExtensionPrototypesUsing.h"
#include "Using/WindowsSockExUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE GetWinSocket(ProtocolFamilies addressFamilies,
                                                            SocketTypes type,
                                                            SocketProtocols protocol,
                                                            SocketProtocolInfoPtr protocolInfo,
                                                            SocketGroup group,
                                                            WindowsDWord flags) noexcept;

    NODISCARD WinSocket SYSTEM_DEFAULT_DECLARE WinSocketAccept(WinSocket winSocket,
                                                               WinSockAddress* addr,
                                                               WindowsIntPtr addrLen,
                                                               WinSockConditionProc condition,
                                                               WindowsDWordPtrSizeType callbackData) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketConnect(WinSocket winSocket,
                                                           const WinSockAddress* name,
                                                           int nameLen,
                                                           WinSockBufPtr callerData,
                                                           WinSockBufPtr calleeData,
                                                           QualityOfServicePtr sQualityOfService,
                                                           QualityOfServicePtr gQualityOfService) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByName(WinSocket winSocket,
                                                                 TChar* nodeName,
                                                                 TChar* serviceName,
                                                                 WindowsDWordPtr localAddressLength,
                                                                 WinSockAddress* localAddress,
                                                                 WindowsDWordPtr remoteAddressLength,
                                                                 WinSockAddress* remoteAddress,
                                                                 const WinSockTimeval* timeout) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketHostToNetLong(WinSocket winSocket,
                                                                 unsigned long hostLong,
                                                                 unsigned long* netLong) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketHostToNetShort(WinSocket winSocket,
                                                                  unsigned short hostShort,
                                                                  unsigned short* netShort) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketNetToHostLong(WinSocket winSocket,
                                                                 unsigned long netLong,
                                                                 unsigned long* hostLong) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WinSocketNetToHostShort(WinSocket winSocket,
                                                                  unsigned short netShort,
                                                                  unsigned short* hostShort) noexcept;

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
                                                           WinSockAddress* from,
                                                           WindowsIntPtr fromLen,
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
                                                         const WinSockAddress* to,
                                                         int toLen,
                                                         SocketOverlappedPtr overlapped,
                                                         SocketOverlappedCompletionRoutine completionRoutine) noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
