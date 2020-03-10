// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_WINDOWS_SOCK_EX_FWD_H 
#define SYSTEM_NETWORK_WINDOWS_SOCK_EX_FWD_H 

#include "NetworkFlagsFwd.h"
#include "System/Network/Using/WindowsSockExUsing.h" 

namespace System
{
	WinSocket WinSocketAccept(WinSocket winSocket, WinSockAddr* addr, WindowIntPtr addrlen, WinSockConditionProc condition, WindowPtrDWord callbackData) noexcept;
	bool WinSocketCloseEvent(WinSockEvent winSockEvent) noexcept;
	bool WinSocketConnect(WinSocket winSocket, const WinSockAddr* name, int namelen, WinSockBufPtr callerData,
						  WinSockBufPtr calleeData, QualityOfServicePtr sQualityOfService, QualityOfServicePtr gQualityOfService) noexcept;
	bool WinSocketConnectByName(WinSocket winSocket, TChar* nodename, TChar* servicename, WindowDWordPtr localAddressLength,
								WinSockAddr* localAddress, WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;

	bool WinSocketConnectByList(WinSocket winSocket, SocketAddressListPtr socketAddress, WindowDWordPtr localAddressLength, WinSockAddr* localAddress,
								WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept;
	WinSockEvent WinSocketCreateEvent() noexcept;

	bool WinSocketEnumNetworkEvents(WinSocket winSocket, WinSockEvent eventObject, SocketNetworkEventsPtr networkEvents) noexcept;

	bool WinSocketEventSelect(WinSocket winSocket, WinSockEvent eventObject, long networkEvents) noexcept;

	bool WinSocketHtonl(WinSocket winSocket, unsigned long  hostlong, unsigned long* netlong) noexcept;
	bool WinSocketHtons(WinSocket winSocket, unsigned short  hostshort, unsigned short* netshort) noexcept;
	bool WinSocketNtohl(WinSocket winSocket, unsigned long  netlong, unsigned long* hostlong) noexcept;
	bool WinSocketNtohs(WinSocket winSocket, unsigned short  netshort, unsigned short* hostshort) noexcept;

	int WinSocketRecv(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd,
					  WindowDWordPtr flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool WinSocketRecvDisconnect(WinSocket winSocket, WinSockBufPtr inboundDisconnectData) noexcept;
	int WinSocketRecvFrom(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd,
						  WindowDWordPtr flags, WinSockAddr* from, WindowIntPtr fromlen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool WinSocketResetEvent(WinSockEvent resetEvent) noexcept;
	int WinSocketSend(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
					  WindowDWord flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	int WinSocketSendMsg(WinSocket winSocket, SocketMsgPtr msg, WindowDWord flags, WindowDWordPtr numberOfBytesSent, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool WinSocketSendDisconnect(WinSocket winSocket, WinSockBufPtr outboundDisconnectData) noexcept;
	int WinSocketSendTo(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
						WindowDWord flags, const WinSockAddr* to, int tolen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept;
	bool WinSocketSetEvent(WinSockEvent setEvent) noexcept;
	WinSocket GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol, SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowDWord flags) noexcept;
	WaitForMultipleEventsReturn WinSocketWaitForMultipleEvents(WindowDWord eventsCount, const WinSockEvent* events, bool waitAll, WindowDWord timeout, bool alertable) noexcept;
}

#endif // SYSTEM_NETWORK_WINDOWS_SOCK_EX_FWD_H