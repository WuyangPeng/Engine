//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:49)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowHandle System::GetStandardHandle([[maybe_unused]] StandardHandle standardhandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetStdHandle(EnumCastUnderlying(standardhandle));
#else  // !SYSTEM_PLATFORM_WIN32
    return g_InvalidHandleValue;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsHandleValid(WindowHandle handle) noexcept
{
    if (handle != g_InvalidHandleValue && handle != nullptr)
        return true;
    else
        return false;
}

bool System::SetStandardHandle([[maybe_unused]] StandardHandle standardhandle, [[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetStdHandle(EnumCastUnderlying(standardhandle), handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetStandardHandle([[maybe_unused]] StandardHandle standardhandle, [[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetStdHandleEx(EnumCastUnderlying(standardhandle), handle, previousHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
