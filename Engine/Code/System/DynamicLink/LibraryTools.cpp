//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:08)

#include "System/SystemExport.h"

#include "LibraryTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::DynamicLinkModule System::GetDynamicLinkHandle([[maybe_unused]] const DynamicLinkCharType* moduleName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetModuleHandle(moduleName);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetDynamicLinkFileName([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] DynamicLinkCharType* filename, [[maybe_unused]] WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetModuleFileName(module, filename, size);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDynamicLinkHandle([[maybe_unused]] GetModuleHandleType flags, [[maybe_unused]] const DynamicLinkCharType* moduleName, [[maybe_unused]] DynamicLinkModule* module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetModuleHandleEx(EnumCastUnderlying(flags), moduleName, module) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
