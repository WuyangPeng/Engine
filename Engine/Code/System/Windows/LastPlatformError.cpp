///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/03 22:00)

#include "System/SystemExport.h"

#include "LastPlatformError.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Platform.h"

System::WindowError System::GetPlatformLastError() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<WindowError>(::GetLastError());

#else  // !SYSTEM_PLATFORM_WIN32

    return WindowError::NoError;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetPlatformLastError(WindowError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::SetLastError(EnumCastUnderlying(error));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowError>(error);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System::GetPlatformErrorMode() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ErrorMode>(::GetErrorMode());

#else  // !SYSTEM_PLATFORM_WIN32

    return ErrorMode::Default;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System::SetPlatformErrorMode(ErrorMode flag) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ErrorMode>(::SetErrorMode(EnumCastUnderlying(flag)));

#else  // !SYSTEM_PLATFORM_WIN32

    return flag;

#endif  // SYSTEM_PLATFORM_WIN32
}
