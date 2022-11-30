///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/16 21:17)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsHandle System::GetStandardHandle(StandardHandle standardhandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStdHandle(EnumCastUnderlying(standardhandle));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardhandle);

    return gInvalidHandleValue;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsHandleValid(WindowsHandle handle) noexcept
{
    if (handle != gInvalidHandleValue && handle != nullptr)
        return true;
    else
        return false;
}

bool System::SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandle(EnumCastUnderlying(standardhandle), handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardhandle, handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetStandardHandle(StandardHandle standardhandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandleEx(EnumCastUnderlying(standardhandle), handle, previousHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardhandle, handle, previousHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
