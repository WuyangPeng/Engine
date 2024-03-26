/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:39)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <array>

bool System::SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetDllDirectory(pathName) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetLibraryDirectory(WindowsDWord bufferLength, DynamicLinkCharType* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetDllDirectory(bufferLength, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(bufferLength, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetLibraryDirectory()
{
    DynamicLinkCharBufferType buffer{};

    if (const auto size = GetLibraryDirectory(gMaxPath - 1, buffer.data());
        0 < size)
    {
        return String{ buffer.data() };
    }
    else
    {
        return String{};
    }
}
