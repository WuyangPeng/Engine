///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/19 19:21)

#include "System/SystemExport.h"

#include "LocalTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::LocalMemoryFree(WindowsHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::LocalFree(memory) != nullptr)
        return false;
    else
        return true;

#else  // !SYSTEM_PLATFORM_WIN32

    delete[] memory;

    return true;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHLocal System::LocalMemoryAlloc(LocalMemory flags, WindowsSize bytes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LocalAlloc(EnumCastUnderlying(flags), bytes);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<LocalMemory>(flags);

    return new (std::nothrow) char[bytes];

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsSize System::GetLocalMemorySize(WindowsHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LocalSize(memory);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHLocal&>(memory);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
