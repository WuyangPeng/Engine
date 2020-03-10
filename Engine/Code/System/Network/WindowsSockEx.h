// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:26)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_H

#include "System/SystemDll.h" 

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsSockExUsing.h"
#include "Using/SocketPrototypesUsing.h" 
#include "Using/WindowsExtensionPrototypesUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"

namespace System
{
	WinSocket SYSTEM_DEFAULT_DECLARE GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol,
												  SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowDWord flags) noexcept;

	WinSocket SYSTEM_DEFAULT_DECLARE WinSocketAccept(WinSocket winSocket, WinSockAddr* addr, WindowIntPtr addrlen, WinSockConditionProc condition, WindowPtrDWord callbackData) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WinSocketConnect(WinSocket winSocket, const WinSockAddr* name, int namelen, WinSockBufPtr callerData,
												 WinSockBufPtr calleeData, QualityOfServicePtr sQualityOfService, QualityOfServicePtr gQualityOfService) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByName(WinSocket winSocket, TChar* nodename, TChar* servicename, WindowDWordPtr localAddressLength,
													   WinSockAddr* localAddress, WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketConnectByList(WinSocket winSocket, SocketAddressListPtr socketAddress, WindowDWordPtr localAddressLength, WinSockAddr* localAddress,
													   WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;

	WinSockEvent SYSTEM_DEFAULT_DECLARE WinSocketCreateEvent() noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketCloseEvent(WinSockEvent winSockEvent) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketEnumNetworkEvents(WinSocket winSocket, WinSockEvent eventObject, SocketNetworkEventsPtr networkEvents) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketEventSelect(WinSocket winSocket, WinSockEvent eventObject, long networkEvents) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketResetEvent(WinSockEvent resetEvent) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketSetEvent(WinSockEvent setEvent) noexcept;
	WaitForMultipleEventsReturn SYSTEM_DEFAULT_DECLARE WinSocketWaitForMultipleEvents(WindowDWord eventsCount, const WinSockEvent* events, bool waitAll, WindowDWord timeout, bool alertable) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WinSocketHtonl(WinSocket winSocket, unsigned long  hostlong, unsigned long* netlong) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketHtons(WinSocket winSocket, unsigned short  hostshort, unsigned short* netshort) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketNtohl(WinSocket winSocket, unsigned long  netlong, unsigned long* hostlong) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketNtohs(WinSocket winSocket, unsigned short  netshort, unsigned short* hostshort) noexcept;

	int SYSTEM_DEFAULT_DECLARE WinSocketRecv(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd,
											 WindowDWordPtr flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketRecvDisconnect(WinSocket winSocket, WinSockBufPtr inboundDisconnectData) noexcept;
	int SYSTEM_DEFAULT_DECLARE WinSocketRecvFrom(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd, WindowDWordPtr flags,
												 WinSockAddr* from, WindowIntPtr fromlen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;

	int SYSTEM_DEFAULT_DECLARE WinSocketSend(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
											 WindowDWord flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	int SYSTEM_DEFAULT_DECLARE WinSocketSendMsg(WinSocket winSocket, SocketMsgPtr msg, WindowDWord flags,
											    WindowDWordPtr numberOfBytesSent, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WinSocketSendDisconnect(WinSocket winSocket, WinSockBufPtr outboundDisconnectData) noexcept;
	int SYSTEM_DEFAULT_DECLARE WinSocketSendTo(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
											   WindowDWord flags, const WinSockAddr* to, int tolen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
}

#endif // SYSTEM_NETWORK_WINDOWS_SOCK_EX_H
