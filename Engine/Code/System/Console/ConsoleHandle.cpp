///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:17)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsHandle System::GetStandardHandle(StandardHandle standardhandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStdHandle(EnumCastUnderlying(standardhandle));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<StandardHandle>(standardhandle);

    return g_InvalidHandleValue;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsHandleValid(WindowsHandle handle) noexcept
{
    if (handle != g_InvalidHandleValue && handle != nullptr)
        return true;
    else
        return false;
}

bool System::SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandle(EnumCastUnderlying(standardhandle), handle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<StandardHandle, WindowsHandle>(standardhandle, handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandleEx(EnumCastUnderlying(standardhandle), handle, previousHandle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<StandardHandle, WindowsHandle, WindowsHandlePtr>(standardhandle, handle, previousHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
