///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/19 20:19)

#include "System/SystemExport.h"

#include "VirtualTools.h"
#include "Flags/VirtualToolsFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsVoidPtr System::AllocateVirtual(WindowsVoidPtr address, WindowsSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::VirtualAlloc(address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsVoidPtr, WindowsSize, MemoryAllocation, MemoryProtect>(address, size, allocationType, protect);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::AllocateVirtual(WindowsHandle process, WindowsVoidPtr address, WindowsSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::VirtualAllocEx(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsVoidPtr, WindowsSize, MemoryAllocation, MemoryProtect>(process, address, size, allocationType, protect);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual(WindowsVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    if (::VirtualFree(address, 0, freeType) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsVoidPtr>(address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual(WindowsHandle process, WindowsVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    if (::VirtualFreeEx(process, address, 0, freeType) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsVoidPtr>(process, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect(WindowsVoidPtr address, WindowsSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsDWord oldMemory{ 0 };
    const auto result = ::VirtualProtect(address, size, EnumCastUnderlying(newProtect), &oldMemory);

    if (result != g_False)
    {
        UnderlyingCastEnumPtr(oldMemory, oldProtect);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsVoidPtr, WindowsSize, MemoryProtect, MemoryProtect*>(address, size, newProtect, oldProtect);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect(WindowsHandle process, WindowsVoidPtr address, WindowsSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsDWord oldMemory{ 0 };
    const auto result = ::VirtualProtectEx(process, address, size, EnumCastUnderlying(newProtect), &oldMemory);

    if (result != g_False)
    {
        UnderlyingCastEnumPtr(oldMemory, oldProtect);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsVoidPtr, WindowsSize, MemoryProtect, MemoryProtect*>(process, address, size, newProtect, oldProtect);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery(WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);

    const auto size = ::VirtualQuery(address, buffer, memoryBasicInformationSize);

    if (size == memoryBasicInformationSize)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsVoidPtr, MemoryBasicInformationPtr>(address, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery(WindowsHandle process, WindowsVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);
    const auto size = ::VirtualQueryEx(process, address, buffer, memoryBasicInformationSize);

    if (size == memoryBasicInformationSize)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsVoidPtr, MemoryBasicInformationPtr>(process, address, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
