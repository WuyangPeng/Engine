///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:37)

#include "System/SystemExport.h"

#include "WindowsSockEx.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::WinSocket System::WinSocketAccept(WinSocket winSocket, WinSockAddr* addr, WindowsIntPtr addrlen, WinSockConditionProc condition, WindowsPtrDWord callbackData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAAccept(winSocket, addr, addrlen, condition, callbackData);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, addr, addrlen, condition, callbackData);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnect(WinSocket winSocket,
                              const WinSockAddr* name,
                              int namelen,
                              WinSockBufPtr callerData,
                              WinSockBufPtr calleeData,
                              QualityOfServicePtr sQualityOfService,
                              QualityOfServicePtr gQualityOfService) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSAConnect(winSocket, name, namelen, callerData, calleeData, sQualityOfService, gQualityOfService) != gSocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, name, namelen, callerData, calleeData, sQualityOfService, gQualityOfService);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnectByName(WinSocket winSocket,
                                    TChar* nodename,
                                    TChar* servicename,
                                    WindowsDWordPtr localAddressLength,
                                    WinSockAddr* localAddress,
                                    WindowsDWordPtr remoteAddressLength,
                                    WinSockAddr* remoteAddress,
                                    const WinSockTimeval* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSAConnectByName(winSocket, nodename, servicename, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, nodename, servicename, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHtonl(WinSocket winSocket, unsigned long hostlong, unsigned long* netlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSAHtonl(winSocket, hostlong, netlong) != gSocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, hostlong, netlong);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHtons(WinSocket winSocket, unsigned short hostshort, unsigned short* netshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSAHtons(winSocket, hostshort, netshort) != gSocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, hostshort, netshort);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNtohl(WinSocket winSocket, unsigned long netlong, unsigned long* hostlong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSANtohl(winSocket, netlong, hostlong) != gSocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, netlong, hostlong);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNtohs(WinSocket winSocket, unsigned short netshort, unsigned short* hostshort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::WSANtohs(winSocket, netshort, hostshort) != gSocketError)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, netshort, hostshort);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecv(WinSocket winSocket,
                          WinSockBufPtr buffers,
                          WindowsDWord bufferCount,
                          WindowsDWordPtr numberOfBytesRecvd,
                          WindowsDWordPtr flags,
                          SocketOverlappedPtr overlapped,
                          SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSARecv(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecvFrom(WinSocket winSocket,
                              WinSockBufPtr buffers,
                              WindowsDWord bufferCount,
                              WindowsDWordPtr numberOfBytesRecvd,
                              WindowsDWordPtr flags,
                              WinSockAddr* from,
                              WindowsIntPtr fromlen,
                              SocketOverlappedPtr overlapped,
                              SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSARecvFrom(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, from, fromlen, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesRecvd, flags, from, fromlen, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketSend(WinSocket winSocket,
                          WinSockBufPtr buffers,
                          WindowsDWord bufferCount,
                          WindowsDWordPtr numberOfBytesSent,
                          WindowsDWord flags,
                          SocketOverlappedPtr overlapped,
                          SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASend(winSocket, buffers, bufferCount, numberOfBytesSent, flags, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesSent, flags, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketSendTo(WinSocket winSocket,
                            WinSockBufPtr buffers,
                            WindowsDWord bufferCount,
                            WindowsDWordPtr numberOfBytesSent,
                            WindowsDWord flags,
                            const WinSockAddr* to,
                            int tolen,
                            SocketOverlappedPtr overlapped,
                            SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASendTo(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, tolen, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, tolen, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol, SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowsDWord flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASocket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol), protocolInfo, group, flags);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(addressFamilies, type, protocol, protocolInfo, group, flags);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}
