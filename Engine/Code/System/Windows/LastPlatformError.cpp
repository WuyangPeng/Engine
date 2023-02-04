///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/02 14:41)

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

    UnusedFunction(error);

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
