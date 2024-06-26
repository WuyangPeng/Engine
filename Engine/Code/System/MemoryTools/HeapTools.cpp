/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 15:58)

#include "System/SystemExport.h"

#include "HeapTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/ExceptionFlags.h"

System::WindowsHandle System::CreateProcessHeap(HeapCreate options, WindowsSize initialSize, WindowsSize maximumSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapCreate(EnumCastUnderlying(options), initialSize, maximumSize);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(options, initialSize, maximumSize);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DestroyProcessHeap(WindowsHandle heap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapDestroy(heap) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::AllocateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    __try
    {
        return ::HeapAlloc(heap, EnumCastUnderlying(flags), bytes);
    }
    __except (EnumCastUnderlying(Exception::ExecuteHandler))
    {
        return nullptr;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap, flags, bytes);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapFree(heap, EnumCastUnderlying(flags), memory) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap, flags, memory);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsSize System::GetProcessHeapSize(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapSize(heap, EnumCastUnderlying(flags), memory);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap, flags, memory);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ValidateProcessHeap(WindowsHandle heap, HeapCreate flags, WindowsVoidPtr memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapValidate(heap, EnumCastUnderlying(flags), memory) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap, flags, memory);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsSize System::GetProcessHeapCompact(WindowsHandle heap, HeapCreate flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::HeapCompact(heap, EnumCastUnderlying(flags));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(heap, flags);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::GetCurrentProcessHeap() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetProcessHeap();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetCurrentProcessHeaps(WindowsDWord numberOfHeaps, WindowsHandlePtr processHeaps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetProcessHeaps(numberOfHeaps, processHeaps);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(numberOfHeaps, processHeaps);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
