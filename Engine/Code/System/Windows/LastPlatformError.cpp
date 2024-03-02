/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/26 13:00)

#include "System/SystemExport.h"

#include "LastPlatformError.h"
#include "Flags/PlatformErrorFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Platform.h"
#include "System/Helper/Tools.h"

#include <gsl/util>

System::WindowError System::GetPlatformLastError() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<WindowError>(gsl::narrow_cast<int>(::GetLastError()));

#else  // !SYSTEM_PLATFORM_WIN32

    return WindowError::NoError;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetPlatformLastError(WindowError error) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::SetLastError(EnumCastUnderlying(error));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(error);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System::GetPlatformErrorMode() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ErrorMode>(gsl::narrow_cast<int>(::GetErrorMode()));

#else  // !SYSTEM_PLATFORM_WIN32

    return ErrorMode::Default;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ErrorMode System::SetPlatformErrorMode(ErrorMode flag) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ErrorMode>(gsl::narrow_cast<int>(::SetErrorMode(EnumCastUnderlying(flag))));

#else  // !SYSTEM_PLATFORM_WIN32

    return flag;

#endif  // SYSTEM_PLATFORM_WIN32
}
