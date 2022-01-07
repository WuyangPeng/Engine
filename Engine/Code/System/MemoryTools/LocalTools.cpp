///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 14:46)

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
