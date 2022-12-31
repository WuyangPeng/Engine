///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/08 18:37)

#include "System/SystemExport.h"

#include "LibraryTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

#include <array>

System::DynamicLinkModule System::GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleHandle(moduleName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(moduleName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDynamicLinkHandle(GetModuleHandleType flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetModuleHandleEx(EnumCastUnderlying(flags), moduleName, module) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flags, moduleName, module);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowsDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleFileName(module, filename, size);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(moduleName, filename, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkString System::GetDynamicLinkFileName(DynamicLinkModule module)
{
    using BufferType = std::array<DynamicLinkCharType, gMaxPath>;

    BufferType moduleFileName{};
    const auto maxFileNameLength = GetDynamicLinkFileName(module, moduleFileName.data(), gMaxPath - 1);

    if (0 < maxFileNameLength)
        return DynamicLinkString{ moduleFileName.data() };
    else
        return DynamicLinkString{};
}
