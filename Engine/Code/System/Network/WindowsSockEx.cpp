/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 21:13)

#include "System/SystemExport.h"

#include "WindowsSockEx.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

System::WinSocket System::WinSocketAccept(WinSocket winSocket, WinSockAddress* address, WindowsIntPtr addressLen, WinSockConditionProc condition, WindowsDWordPtrSizeType callbackData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAAccept(winSocket, address, addressLen, condition, callbackData);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, address, addressLen, condition, callbackData);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnect(WinSocket winSocket,
                              const WinSockAddress* name,
                              int nameLen,
                              WinSockBufPtr callerData,
                              WinSockBufPtr calleeData,
                              QualityOfServicePtr sQualityOfService,
                              QualityOfServicePtr gQualityOfService) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAConnect(winSocket, name, nameLen, callerData, calleeData, sQualityOfService, gQualityOfService) != socketError;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, name, nameLen, callerData, calleeData, sQualityOfService, gQualityOfService);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketConnectByName(WinSocket winSocket,
                                    TChar* nodeName,
                                    TChar* serviceName,
                                    WindowsDWordPtr localAddressLength,
                                    WinSockAddress* localAddress,
                                    WindowsDWordPtr remoteAddressLength,
                                    WinSockAddress* remoteAddress,
                                    const WinSockTimeVal* timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAConnectByName(winSocket, nodeName, serviceName, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout, nullptr) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, nodeName, serviceName, localAddressLength, localAddress, remoteAddressLength, remoteAddress, timeout);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHostToNetLong(WinSocket winSocket, unsigned long hostLong, unsigned long* netLong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAHtonl(winSocket, hostLong, netLong) != socketError;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, hostLong, netLong);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketHostToNetShort(WinSocket winSocket, unsigned short hostShort, unsigned short* netShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSAHtons(winSocket, hostShort, netShort) != socketError;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, hostShort, netShort);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNetToHostLong(WinSocket winSocket, unsigned long netLong, unsigned long* hostLong) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSANtohl(winSocket, netLong, hostLong) != socketError;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, netLong, hostLong);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WinSocketNetToHostShort(WinSocket winSocket, unsigned short netShort, unsigned short* hostShort) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSANtohs(winSocket, netShort, hostShort) != socketError;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, netShort, hostShort);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecv(WinSocket winSocket,
                          WinSockBufPtr buffers,
                          WindowsDWord bufferCount,
                          WindowsDWordPtr numberOfBytesRecvD,
                          WindowsDWordPtr flags,
                          SocketOverlappedPtr overlapped,
                          SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSARecv(winSocket, buffers, bufferCount, numberOfBytesRecvD, flags, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesRecvD, flags, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WinSocketRecvFrom(WinSocket winSocket,
                              WinSockBufPtr buffers,
                              WindowsDWord bufferCount,
                              WindowsDWordPtr numberOfBytesRecvD,
                              WindowsDWordPtr flags,
                              WinSockAddress* from,
                              WindowsIntPtr fromLen,
                              SocketOverlappedPtr overlapped,
                              SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSARecvFrom(winSocket, buffers, bufferCount, numberOfBytesRecvD, flags, from, fromLen, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesRecvD, flags, from, fromLen, overlapped, completionRoutine);

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
                            const WinSockAddress* to,
                            int toLen,
                            SocketOverlappedPtr overlapped,
                            SocketOverlappedCompletionRoutine completionRoutine) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASendTo(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, toLen, overlapped, completionRoutine);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(winSocket, buffers, bufferCount, numberOfBytesSent, flags, to, toLen, overlapped, completionRoutine);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSocket System::GetWinSocket(ProtocolFamilies addressFamilies, SocketTypes type, SocketProtocols protocol, SocketProtocolInfoPtr protocolInfo, SocketGroup group, WindowsDWord flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASocket(EnumCastUnderlying(addressFamilies), EnumCastUnderlying(type), EnumCastUnderlying(protocol), protocolInfo, group, flags);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(addressFamilies, type, protocol, protocolInfo, group, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
