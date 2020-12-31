//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:14)

#include "System/SystemExport.h"

#include "WindowsExtensionPrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"

System::WinSockStartUpReturn System::WinSockStartUp([[maybe_unused]] WindowWord versionRequired, [[maybe_unused]] WinSockDataPtr wSAData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<WinSockStartUpReturn>(::WSAStartup(versionRequired, wSAData));
#else  // !SYSTEM_PLATFORM_WIN32
    return WinSockStartUpReturn::VerNotSupported;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockCleanupReturn System::WinSockCleanup() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<WinSockCleanupReturn>(::WSACleanup());
#else  // !SYSTEM_PLATFORM_WIN32
    return WinSockCleanupReturn::NotInitialised;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetWinSockLastError([[maybe_unused]] WinSockLastError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WSASetLastError(EnumCastUnderlying(error));
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WinSockLastError System::GetWinSockLastError() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<WinSockLastError>(::WSAGetLastError());
#else  // !SYSTEM_PLATFORM_WIN32
    return WinSockLastError::BaseErr;
#endif  // SYSTEM_PLATFORM_WIN32
}
