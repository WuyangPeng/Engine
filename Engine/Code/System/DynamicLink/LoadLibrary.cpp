///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/24 15:42)

#include "System/SystemExport.h"

#include "LoadLibrary.h"
#include "Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::DynamicLinkModule System::LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibraryType flag) noexcept
{
    if (flag == LoadLibraryType::NoFlags)
    {
        flag = LoadLibraryType::Zero;
    }

#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadLibraryEx(fileName, nullptr, EnumCastUnderlying(flag));

#else  // !SYSTEM_PLATFORM_WIN32

    return ::dlopen(fileName, flag);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeDynamicLibrary(DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FreeLibrary(module) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    if (::dlclose(module) != 0)
        return false;
    else
        return true;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkProcess System::GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetProcAddress(module, processName);

#else  // !SYSTEM_PLATFORM_WIN32

    return ::dlsym(module, processName);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DisableThreadLibraryCalls(module) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<DynamicLinkModule>(module);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
