/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:29)

#include "System/SystemExport.h"

#include "WindowsExtensionPrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"

System::WinSockStartUpReturn System::WinSockStartUp(WindowsWord versionRequired, WinSockDataPtr wsaData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<WinSockStartUpReturn>(::WSAStartup(versionRequired, wsaData));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(versionRequired, wsaData);

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

void System::SetWinSockLastError(WinSockLastError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::WSASetLastError(EnumCastUnderlying(error));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(error);

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
