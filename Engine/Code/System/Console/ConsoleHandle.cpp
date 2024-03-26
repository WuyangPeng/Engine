/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:01)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsHandle System::GetStandardHandle(StandardHandle standardHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStdHandle(EnumCastUnderlying(standardHandle));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle);

    return invalidHandleValue;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsHandleValid(WindowsHandle handle) noexcept
{
    return handle != invalidHandleValue && handle != nullptr;
}

bool System::SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetStdHandle(EnumCastUnderlying(standardHandle), handle) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle, handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetStdHandleEx(EnumCastUnderlying(standardHandle), handle, previousHandle) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle, handle, previousHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
