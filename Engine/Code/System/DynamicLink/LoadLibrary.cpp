/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:39)

#include "System/SystemExport.h"

#include "LoadLibrary.h"
#include "Flags/LoadLibraryFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
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

    return ::dlopen(fileName, EnumCastUnderlying(flag));

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeDynamicLibrary(DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FreeLibrary(module) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    return ::dlclose(module) != 0;

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

    return ::DisableThreadLibraryCalls(module) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
