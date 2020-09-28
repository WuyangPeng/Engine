//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:05)

#include "System/SystemExport.h"

#include "MemoryHelper.h"
#include "Using/VirtualToolsUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/WindowSystem.h"

#include <cstdlib>

bool System::ReadMemoryOnProcess([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowConstVoidPtr baseAddress, [[maybe_unused]] WindowVoidPtr buffer, [[maybe_unused]] WindowSize size, [[maybe_unused]] WindowSize* numberOfBytesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReadProcessMemory(process, baseAddress, buffer, size, numberOfBytesRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteMemoryOnProcess([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowVoidPtr baseAddress, [[maybe_unused]] WindowConstVoidPtr buffer, [[maybe_unused]] WindowSize size, [[maybe_unused]] WindowSize* numberOfBytesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::WriteProcessMemory(process, baseAddress, buffer, size, numberOfBytesWritten) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System::GetMinimumLargePageSize() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetLargePageMinimum();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetProcessWorkingSize([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowSizePtr minimumWorkingSetSize, [[maybe_unused]] WindowSizePtr maximumWorkingSetSize, [[maybe_unused]] WorkingSetSizesQuotaLimits* flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowDWord workingSetSizesFlags{ 0 };
    const auto result = ::GetProcessWorkingSetSizeEx(process, minimumWorkingSetSize, maximumWorkingSetSize, &workingSetSizesFlags);

    if (result != g_False)
    {
        UnderlyingCastEnumPtr(workingSetSizesFlags, flags);

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

bool System::SetProcessWorkingSize([[maybe_unused]] WindowHandle process, [[maybe_unused]] WindowSize minimumWorkingSetSize, [[maybe_unused]] WindowSize maximumWorkingSetSize, [[maybe_unused]] WorkingSetSizesQuotaLimits flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetProcessWorkingSetSizeEx(process, minimumWorkingSetSize, maximumWorkingSetSize, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateMemoryResourceNotificationUseNotificationType([[maybe_unused]] MemoryResourceNotificationType notificationType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateMemoryResourceNotification(notificationType);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::QueryMemoryResourceNotificationState([[maybe_unused]] WindowHandle resourceNotificationHandle, [[maybe_unused]] bool* resourceState) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool resourceStateResult{};
    if (::QueryMemoryResourceNotification(resourceNotificationHandle, &resourceStateResult) != g_False)
    {
        BoolConversion(resourceStateResult, resourceState);

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

bool System::CloseMemoryResourceNotificationHandle([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(handle) == 0)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::MemorySet(void* bytes, int value, int byteSize) noexcept
{
    ::memset(bytes, value, byteSize);
}

void System::MemoryCopy(void* dst, const void* src, uint32_t count) noexcept
{
    ::memcpy(dst, src, count);
}

void* System::MallocMemory(size_t size) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)
    return ::malloc(size);
#include STSTEM_WARNING_POP
}

void System::FreeMemory(void* memory) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)
    ::free(memory);
#include STSTEM_WARNING_POP
}
