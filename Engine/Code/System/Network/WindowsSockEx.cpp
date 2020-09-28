//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:17)

#include "System/SystemExport.h"

#include "WindowsSockEx.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WinSocket System::WinSocketAccept([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockAddr* addr, [[maybe_unused]] WindowIntPtr addrlen, [[maybe_unused]] WinSockConditionProc condition, [[maybe_unused]] WindowPtrDWord callbackData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSAAccept(winSocket, addr, addrlen, condition, callbackData);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketCloseEvent([[maybe_unused]] WinSockEvent winSockEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSACloseEvent(winSockEvent) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnect([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] const WinSockAddr* name, [[maybe_unused]] int namelen, [[maybe_unused]] WinSockBufPtr callerData,
                              [[maybe_unused]] WinSockBufPtr calleeData, [[maybe_unused]] QualityOfServicePtr sQualityOfService, [[maybe_unused]] QualityOfServicePtr gQualityOfService) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAConnect(winSocket, name, namelen, callerData, calleeData, sQualityOfService, gQualityOfService) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnectByName([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] TChar* nodename, [[maybe_unused]] TChar* servicename, [[maybe_unused]] WindowDWordPtr localAddressLength,
                                    [[maybe_unused]] WinSockAddr* localAddress, [[maybe_unused]] WindowDWordPtr remoteAddressLength, [[maybe_unused]] WinSockAddr* remoteAddress, [[maybe_unused]] const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAConnectByName(winSocket, nodename, servicename, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnectByList([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] SocketAddressListPtr socketAddress, [[maybe_unused]] WindowDWordPtr localAddressLength, [[maybe_unused]] WinSockAddr* localAddress,
                                    [[maybe_unused]] WindowDWordPtr remoteAddressLength, [[maybe_unused]] WinSockAddr* remoteAddress, [[maybe_unused]] const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAConnectByList(winSocket, socketAddress, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockEvent System::WinSocketCreateEvent() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSACreateEvent();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketEnumNetworkEvents([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockEvent eventObject, [[maybe_unused]] SocketNetworkEventsPtr networkEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAEnumNetworkEvents(winSocket, eventObject, networkEvents) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketEventSelect([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockEvent eventObject, [[maybe_unused]] long networkEvents) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAEventSelect(winSocket, eventObject, networkEvents) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHtonl([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] unsigned long hostlong, [[maybe_unused]] unsigned long* netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAHtonl(winSocket, hostlong, netlong) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHtons([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] unsigned short hostshort, [[maybe_unused]] unsigned short* netshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAHtons(winSocket, hostshort, netshort) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNtohl([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] unsigned long netlong, [[maybe_unused]] unsigned long* hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSANtohl(winSocket, netlong, hostlong) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNtohs([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] unsigned short netshort, [[maybe_unused]] unsigned short* hostshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSANtohs(winSocket, netshort, hostshort) != g_SocketError)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecv([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr buffers, [[maybe_unused]] WindowDWord bufferCount, [[maybe_unused]] WindowDWordPtr numberOfBytesRecvd,
                          [[maybe_unused]] WindowDWordPtr flags, [[maybe_unused]] SocketOverlappedPtr overlapped, [[maybe_unused]] SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSARecv(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, overlapped, completionRoutine);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketRecvDisconnect([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr inboundDisconnectData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    if (::WSARecvDisconnect(winSocket, inboundDisconnectData) != g_SocketError)
        return true;
    else
        return false;
    #include STSTEM_WARNING_POP
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketSendDisconnect([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr outboundDisconnectData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4996)
    if (::WSASendDisconnect(winSocket, outboundDisconnectData) != g_SocketError)
        return true;
    else
        return false;
    #include STSTEM_WARNING_POP
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecvFrom([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr buffers, [[maybe_unused]] WindowDWord bufferCount, [[maybe_unused]] WindowDWordPtr numberOfBytesRecvd, [[maybe_unused]] WindowDWordPtr flags,
                              [[maybe_unused]] WinSockAddr* from, [[maybe_unused]] WindowIntPtr fromlen, SocketOverlappedPtr overlapped, [[maybe_unused]] SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSARecvFrom(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, from, fromlen, overlapped, completionRoutine);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketResetEvent([[maybe_unused]] WinSockEvent resetEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSAResetEvent(resetEvent) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketSend([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr buffers, [[maybe_unused]] WindowDWord bufferCount, [[maybe_unused]] WindowDWordPtr numberOfBytesSent,
                          [[maybe_unused]] WindowDWord flags, [[maybe_unused]] SocketOverlappedPtr overlapped, [[maybe_unused]] SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSASend(winSocket, buffers, bufferCount, numberOfBytesSent, flags, overlapped, completionRoutine);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketSendMsg([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] SocketMsgPtr msg, [[maybe_unused]] WindowDWord flags, [[maybe_unused]] WindowDWordPtr numberOfBytesSent, [[maybe_unused]] SocketOverlappedPtr overlapped, [[maybe_unused]] SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSASendMsg(winSocket, msg, flags, numberOfBytesSent, overlapped, completionRoutine);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketSendTo([[maybe_unused]] WinSocket winSocket, [[maybe_unused]] WinSockBufPtr buffers, [[maybe_unused]] WindowDWord bufferCount, [[maybe_unused]] WindowDWordPtr numberOfBytesSent,
                            [[maybe_unused]] WindowDWord flags, [[maybe_unused]] const WinSockAddr* to, [[maybe_unused]] int tolen, [[maybe_unused]] SocketOverlappedPtr overlapped, [[maybe_unused]] SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSASendTo(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, tolen, overlapped, completionRoutine);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketSetEvent([[maybe_unused]] WinSockEvent setEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WSASetEvent(setEvent) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::GetWinSocket([[maybe_unused]] ProtocolFamilies addressFamilies, [[maybe_unused]] SocketTypes type, [[maybe_unused]] SocketProtocols protocol, [[maybe_unused]] SocketProtocolInfoPtr protocolInfo, [[maybe_unused]] SocketGroup group, [[maybe_unused]] WindowDWord flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSASocket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol), protocolInfo, group, flags);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WaitForMultipleEventsReturn System::WinSocketWaitForMultipleEvents([[maybe_unused]] WindowDWord eventsCount, [[maybe_unused]] const WinSockEvent* events, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord timeout, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<WaitForMultipleEventsReturn>(::WSAWaitForMultipleEvents(eventsCount, events, BoolConversion(waitAll), timeout, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return WaitForMultipleEventsReturn::WaitFailed;
#endif  // SYSTEM_PLATFORM_WIN32
}
