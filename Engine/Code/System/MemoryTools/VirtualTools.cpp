///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/19 20:53)

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

    if (::VirtualFree(address, 0, freeType) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeVirtual(WindowsHandle process, WindowsVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

    if (::VirtualFreeEx(process, address, 0, freeType) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(process, address);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetVirtualProtect(WindowsVoidPtr address, WindowsSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsDWord oldMemory{ 0 };
    const auto result = ::VirtualProtect(address, size, EnumCastUnderlying(newProtect), &oldMemory);

    if (result != gFalse)
    {
        UnderlyingCastEnumPtr(oldMemory, oldProtect);

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
    const auto result = ::VirtualProtectEx(process, address, size, EnumCastUnderlying(newProtect), &oldMemory);

    if (result != gFalse)
    {
        UnderlyingCastEnumPtr(oldMemory, oldProtect);

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

    const auto size = ::VirtualQuery(address, buffer, memoryBasicInformationSize);

    if (size == memoryBasicInformationSize)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(address, buffer);

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

    UnusedFunction(process, address, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
