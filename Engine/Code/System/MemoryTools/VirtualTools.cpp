/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 16:00)

#include "System/SystemExport.h"

#include "VirtualTools.h"
#include "Flags/VirtualToolsFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <gsl/util>

System::WindowsVoidPtr System::AllocateVirtual(WindowsVoidPtr address, WindowsSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::VirtualAlloc(address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, size, allocationType, protect);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::AllocateVirtual(WindowsHandle process, WindowsVoidPtr address, WindowsSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::VirtualAllocEx(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, address, size, allocationType, protect);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual(WindowsVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    return ::VirtualFree(address, 0, freeType) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual(WindowsHandle process, WindowsVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    return ::VirtualFreeEx(process, address, 0, freeType) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect(WindowsVoidPtr address, WindowsSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsDWord oldMemory{ 0 };

    if (const auto result = ::VirtualProtect(address, size, EnumCastUnderlying(newProtect), &oldMemory);
        result != gFalse)
    {
        UnderlyingCastEnumPtr(gsl::narrow_cast<int>(oldMemory), oldProtect);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, size, newProtect, oldProtect);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect(WindowsHandle process, WindowsVoidPtr address, WindowsSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsDWord oldMemory{ 0 };

    if (const auto result = ::VirtualProtectEx(process, address, size, EnumCastUnderlying(newProtect), &oldMemory);
        result != gFalse)
    {
        UnderlyingCastEnumPtr(gsl::narrow_cast<int>(oldMemory), oldProtect);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, address, size, newProtect, oldProtect);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery(WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);

    return VirtualQuery(address, buffer, memoryBasicInformationSize) == memoryBasicInformationSize;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery(WindowsHandle process, WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);

    return ::VirtualQueryEx(process, address, buffer, memoryBasicInformationSize) == memoryBasicInformationSize;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, address, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
