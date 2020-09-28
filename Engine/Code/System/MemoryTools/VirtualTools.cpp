//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:09)

#include "System/SystemExport.h"

#include "VirtualTools.h"
#include "Flags/VirtualToolsFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowVoidPtr System::AllocateVirtual([[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size, [[maybe_unused]] MemoryAllocation allocationType, [[maybe_unused]] MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::VirtualAlloc(address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::AllocateVirtual([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size, [[maybe_unused]] MemoryAllocation allocationType, [[maybe_unused]] MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::VirtualAllocEx(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual([[maybe_unused]] WindowVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    if (::VirtualFree(address, 0, freeType) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    if (::VirtualFreeEx(process, address, 0, freeType) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect([[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size, [[maybe_unused]] MemoryProtect newProtect, [[maybe_unused]] MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowDWord oldMemory{ 0 };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size, [[maybe_unused]] MemoryProtect newProtect, [[maybe_unused]] MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowDWord oldMemory{ 0 };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery([[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);

    const auto size = ::VirtualQuery(address, buffer, memoryBasicInformationSize);

    if (size == memoryBasicInformationSize)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetVirtualQuery([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);
    const auto size = ::VirtualQueryEx(process, address, buffer, memoryBasicInformationSize);

    if (size == memoryBasicInformationSize)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LockVirtual([[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::VirtualLock(address, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnlockVirtual([[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::VirtualUnlock(address, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::GetVirtualAllocNuma([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr address, [[maybe_unused]] WindowSize size, [[maybe_unused]] MemoryAllocation allocationType, [[maybe_unused]] MemoryProtect protect, [[maybe_unused]] WindowDWord preferred) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::VirtualAllocExNuma(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect), preferred);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}
