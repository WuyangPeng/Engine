///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:01)

#include "System/SystemExport.h"

#include "LocalTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
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

    UnusedFunction(flags);

    return new (std::nothrow) char[bytes];

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsSize System::GetLocalMemorySize(WindowsHLocal& memory) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LocalSize(memory);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(memory);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
