// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:27)

#include "System/SystemExport.h"

#include "WindowsExtensionPrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/EnumCast.h"

System::WinSockStartUpReturn System
	::WinSockStartUp(WindowWord versionRequired, WinSockDataPtr wSAData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<WinSockStartUpReturn>(::WSAStartup(versionRequired, wSAData));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(versionRequired);
	SYSTEM_UNUSED_ARG(wSAData);

	return WinSockStartUpReturn::VerNotSupported;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WinSockCleanupReturn System
	::WinSockCleanup() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<WinSockCleanupReturn>(::WSACleanup());
#else // !SYSTEM_PLATFORM_WIN32
	return WinSockCleanupReturn::NotInitialised;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetWinSockLastError(WinSockLastError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::WSASetLastError(EnumCastUnderlying(error));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(error);
#endif // SYSTEM_PLATFORM_WIN32
}

System::WinSockLastError System
	::GetWinSockLastError() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<WinSockLastError>(::WSAGetLastError());
#else // !SYSTEM_PLATFORM_WIN32
	return WinSockLastError::BaseErr;
#endif // SYSTEM_PLATFORM_WIN32
}











