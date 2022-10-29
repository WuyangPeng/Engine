///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/08 21:49)

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

    if (::FreeLibrary(module) != gFalse)
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

    if (::DisableThreadLibraryCalls(module) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
