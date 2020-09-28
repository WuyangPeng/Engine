//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:04)

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
    [[nodiscard]] WinSocket SYSTEM_DEFAULT_DECLARE GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol,
                                                                SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowDWord flags) noexcept;

    [[nodiscard]] WinSocket SYSTEM_DEFAULT_DECLARE WinSocketAccept(WinSocket winSocket, WinSockAddr* addr, WindowIntPtr addrlen, WinSockConditionProc condition, WindowPtrDWord callbackData) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketConnect(WinSocket winSocket, const WinSockAddr* name, int namelen, WinSockBufPtr callerData,
                                                               WinSockBufPtr calleeData, QualityOfServicePtr sQualityOfService, QualityOfServicePtr gQualityOfService) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByName(WinSocket winSocket, TChar* nodename, TChar* servicename, WindowDWordPtr localAddressLength,
                                                                     WinSockAddr* localAddress, WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByList(WinSocket winSocket, SocketAddressListPtr socketAddress, WindowDWordPtr localAddressLength, WinSockAddr* localAddress,
                                                                     WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;

    [[nodiscard]] WinSockEvent SYSTEM_DEFAULT_DECLARE WinSocketCreateEvent() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketCloseEvent(WinSockEvent winSockEvent) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketEnumNetworkEvents(WinSocket winSocket, WinSockEvent eventObject, SocketNetworkEventsPtr networkEvents) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketEventSelect(WinSocket winSocket, WinSockEvent eventObject, long networkEvents) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketResetEvent(WinSockEvent resetEvent) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketSetEvent(WinSockEvent setEvent) noexcept;
    [[nodiscard]] WaitForMultipleEventsReturn SYSTEM_DEFAULT_DECLARE WinSocketWaitForMultipleEvents(WindowDWord eventsCount, const WinSockEvent* events, bool waitAll, WindowDWord timeout, bool alertable) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketHtonl(WinSocket winSocket, unsigned long hostlong, unsigned long* netlong) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketHtons(WinSocket winSocket, unsigned short hostshort, unsigned short* netshort) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketNtohl(WinSocket winSocket, unsigned long netlong, unsigned long* hostlong) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketNtohs(WinSocket winSocket, unsigned short netshort, unsigned short* hostshort) noexcept;

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE WinSocketRecv(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd,
                                                           WindowDWordPtr flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketRecvDisconnect(WinSocket winSocket, WinSockBufPtr inboundDisconnectData) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE WinSocketRecvFrom(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd, WindowDWordPtr flags,
                                                               WinSockAddr* from, WindowIntPtr fromlen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE WinSocketSend(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
                                                           WindowDWord flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE WinSocketSendMsg(WinSocket winSocket, SocketMsgPtr msg, WindowDWord flags,
                                                              WindowDWordPtr numberOfBytesSent, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WinSocketSendDisconnect(WinSocket winSocket, WinSockBufPtr outboundDisconnectData) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE WinSocketSendTo(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
                                                             WindowDWord flags, const WinSockAddr* to, int tolen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
