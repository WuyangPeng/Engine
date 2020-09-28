//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:13)

#include "System/SystemExport.h"

#include "HandleTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::SetThreadHandleInformation([[maybe_unused]] ThreadHandle object, [[maybe_unused]] HandleInformation mask, [[maybe_unused]] HandleInformation flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetHandleInformation(object, EnumCastUnderlying(mask), EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetThreadHandleInformation([[maybe_unused]] ThreadHandle object, [[maybe_unused]] HandleInformation* flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowDWord information{ 0 };
    if (::GetHandleInformation(object, &information) != g_False)
    {
        UnderlyingCastEnumPtr(information, flags);

        return true;
    }
    else
    {
        return false;
    }
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DuplicateThreadHandle([[maybe_unused]] WindowHandle sourceProcessHandle, [[maybe_unused]] ThreadHandle sourceHandle, [[maybe_unused]] WindowHandle targetProcessHandle, [[maybe_unused]] ThreadHandlePtr targetHandle,
                                   [[maybe_unused]] WindowDWord desiredAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] DuplicateOptions options) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DuplicateHandle(sourceProcessHandle, sourceHandle, targetProcessHandle, targetHandle, desiredAccess, BoolConversion(inheritHandle), EnumCastUnderlying(options)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
