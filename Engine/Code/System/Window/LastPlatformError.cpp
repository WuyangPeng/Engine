// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:38)

#include "System/SystemExport.h"

#include "LastPlatformError.h"
#include "System/Helper/Platform.h"
#include "System/Helper/EnumCast.h"

System::WindowError System
	::GetPlatformLastError() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return UnderlyingCastEnum<WindowError>(::GetLastError());
#else // !SYSTEM_PLATFORM_WIN32
	return WindowError::NoError;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetPlatformLastError(WindowError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::SetLastError(EnumCastUnderlying(error));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(error);
#endif // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System
	::GetPlatformErrorMode() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<ErrorMode>(::GetErrorMode());
#else // !SYSTEM_PLATFORM_WIN32
	return ErrorMode::Default;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System
	::SetPlatformErrorMode(ErrorMode flag) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<ErrorMode>(::SetErrorMode(EnumCastUnderlying(flag)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flag);
#endif // SYSTEM_PLATFORM_WIN32
}

