// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:28)

#include "System/SystemExport.h"

#include "WindowsSockEx.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"

System::WinSocket System
	::WinSocketAccept(WinSocket winSocket, WinSockAddr* addr, WindowIntPtr addrlen, WinSockConditionProc condition, WindowPtrDWord callbackData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSAAccept(winSocket, addr, addrlen, condition, callbackData);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(addr);
	SYSTEM_UNUSED_ARG(addrlen);
	SYSTEM_UNUSED_ARG(condition);
	SYSTEM_UNUSED_ARG(callbackData);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::WinSocketCloseEvent(WinSockEvent winSockEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSACloseEvent(winSockEvent) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSockEvent);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketConnect(WinSocket winSocket, const WinSockAddr* name, int namelen, WinSockBufPtr callerData,
					   WinSockBufPtr calleeData, QualityOfServicePtr sQualityOfService, QualityOfServicePtr gQualityOfService) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAConnect(winSocket, name, namelen, callerData, calleeData, sQualityOfService, gQualityOfService) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(callerData);
	SYSTEM_UNUSED_ARG(calleeData);
	SYSTEM_UNUSED_ARG(sQualityOfService);
	SYSTEM_UNUSED_ARG(gQualityOfService);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketConnectByName(WinSocket winSocket, TChar* nodename, TChar* servicename, WindowDWordPtr localAddressLength,
							 WinSockAddr* localAddress, WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAConnectByName(winSocket, nodename, servicename, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(nodename);
	SYSTEM_UNUSED_ARG(servicename);
	SYSTEM_UNUSED_ARG(localAddressLength);
	SYSTEM_UNUSED_ARG(localAddress);
	SYSTEM_UNUSED_ARG(remoteAddressLength);
	SYSTEM_UNUSED_ARG(remoteAddress);
	SYSTEM_UNUSED_ARG(timeout);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketConnectByList(WinSocket winSocket, SocketAddressListPtr socketAddress, WindowDWordPtr localAddressLength, WinSockAddr* localAddress,
							 WindowDWordPtr remoteAddressLength, WinSockAddr* remoteAddress, const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAConnectByList(winSocket, socketAddress, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(socketAddress);
	SYSTEM_UNUSED_ARG(localAddressLength);
	SYSTEM_UNUSED_ARG(localAddress);
	SYSTEM_UNUSED_ARG(remoteAddressLength);
	SYSTEM_UNUSED_ARG(remoteAddress);
	SYSTEM_UNUSED_ARG(timeout);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WinSockEvent System
	::WinSocketCreateEvent() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSACreateEvent();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::WinSocketEnumNetworkEvents(WinSocket winSocket, WinSockEvent eventObject, SocketNetworkEventsPtr networkEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAEnumNetworkEvents(winSocket, eventObject, networkEvents) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(eventObject);
	SYSTEM_UNUSED_ARG(networkEvents);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketEventSelect(WinSocket winSocket, WinSockEvent eventObject, long networkEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAEventSelect(winSocket, eventObject, networkEvents) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(eventObject);
	SYSTEM_UNUSED_ARG(networkEvents);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketHtonl(WinSocket winSocket, unsigned long hostlong, unsigned long* netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAHtonl(winSocket, hostlong, netlong) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(hostlong);
	SYSTEM_UNUSED_ARG(netlong);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketHtons(WinSocket winSocket, unsigned short hostshort, unsigned short* netshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAHtons(winSocket, hostshort, netshort) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(hostshort);
	SYSTEM_UNUSED_ARG(netshort);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketNtohl(WinSocket winSocket, unsigned long netlong, unsigned long* hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSANtohl(winSocket, netlong, hostlong) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(netlong);
	SYSTEM_UNUSED_ARG(hostlong);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketNtohs(WinSocket winSocket, unsigned short netshort, unsigned short* hostshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSANtohs(winSocket, netshort, hostshort) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(netshort);
	SYSTEM_UNUSED_ARG(hostshort);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::WinSocketRecv(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd,
					WindowDWordPtr flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSARecv(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, overlapped, completionRoutine);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buffers);
	SYSTEM_UNUSED_ARG(bufferCount);
	SYSTEM_UNUSED_ARG(numberOfBytesRecvd);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4996)

bool System
	::WinSocketRecvDisconnect(WinSocket winSocket, WinSockBufPtr inboundDisconnectData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	
	if (::WSARecvDisconnect(winSocket, inboundDisconnectData) != g_SocketError)
		return true;
	else
		return false;
	
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(inboundDisconnectData);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WinSocketSendDisconnect(WinSocket winSocket, WinSockBufPtr outboundDisconnectData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	 

	if (::WSASendDisconnect(winSocket, outboundDisconnectData) != g_SocketError)
		return true;
	else
		return false;
	 
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(outboundDisconnectData);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

#include STSTEM_WARNING_POP

int System
	::WinSocketRecvFrom(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesRecvd, WindowDWordPtr flags,
						WinSockAddr* from, WindowIntPtr fromlen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSARecvFrom(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, from, fromlen, overlapped, completionRoutine);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buffers);
	SYSTEM_UNUSED_ARG(bufferCount);
	SYSTEM_UNUSED_ARG(numberOfBytesRecvd);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(from);
	SYSTEM_UNUSED_ARG(fromlen);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::WinSocketResetEvent(WinSockEvent resetEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSAResetEvent(resetEvent) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(resetEvent);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::WinSocketSend(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
					WindowDWord flags, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSASend(winSocket, buffers, bufferCount, numberOfBytesSent, flags, overlapped, completionRoutine);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buffers);
	SYSTEM_UNUSED_ARG(bufferCount);
	SYSTEM_UNUSED_ARG(numberOfBytesSent);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

int System
	::WinSocketSendMsg(WinSocket winSocket, SocketMsgPtr msg, WindowDWord flags, WindowDWordPtr numberOfBytesSent, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSASendMsg(winSocket, msg, flags, numberOfBytesSent, overlapped, completionRoutine);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(numberOfBytesSent);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

int System
	::WinSocketSendTo(WinSocket winSocket, WinSockBufPtr buffers, WindowDWord bufferCount, WindowDWordPtr numberOfBytesSent,
					  WindowDWord flags, const WinSockAddr* to, int tolen, SocketOverlappedPtr overlapped, SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSASendTo(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, tolen, overlapped, completionRoutine);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(winSocket);
	SYSTEM_UNUSED_ARG(buffers);
	SYSTEM_UNUSED_ARG(bufferCount);
	SYSTEM_UNUSED_ARG(numberOfBytesSent);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(to);
	SYSTEM_UNUSED_ARG(tolen);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(completionRoutine);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::WinSocketSetEvent(WinSockEvent setEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WSASetEvent(setEvent) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(setEvent);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSocket System
	::GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol, SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowDWord flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSASocket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol), protocolInfo, group, flags);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(addressFamilies);
	SYSTEM_UNUSED_ARG(type);
	SYSTEM_UNUSED_ARG(protocol);
	SYSTEM_UNUSED_ARG(protocolInfo);
	SYSTEM_UNUSED_ARG(group);
	SYSTEM_UNUSED_ARG(flags);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WaitForMultipleEventsReturn System
	::WinSocketWaitForMultipleEvents(WindowDWord eventsCount, const WinSockEvent* events, bool waitAll, WindowDWord timeout, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<WaitForMultipleEventsReturn>(::WSAWaitForMultipleEvents(eventsCount, events, BoolConversion(waitAll), timeout, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(eventsCount);
	SYSTEM_UNUSED_ARG(events);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(timeout);
	SYSTEM_UNUSED_ARG(alertable);

	return WaitForMultipleEventsReturn::WaitFailed;
#endif // SYSTEM_PLATFORM_WIN32
}
