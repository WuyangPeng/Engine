///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:36)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <array>

bool System::SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetDllDirectory(pathName) != gFalse)
        return true;
    else
        return false;

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
    using BufferType = std::array<DynamicLinkCharType, gMaxPath>;

    BufferType buffer{};

    if (const auto size = GetLibraryDirectory(gMaxPath - 1, buffer.data());
        0 < size)
        return String{ buffer.data() };
    else
        return String{};
}
