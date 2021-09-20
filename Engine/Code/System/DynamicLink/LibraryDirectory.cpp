///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/24 15:33)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/WindowsMacro.h"

bool System::SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetDllDirectory(pathName) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const DynamicLinkCharType*>(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetLibraryDirectory(WindowsDWord bufferLength, DynamicLinkCharType* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetDllDirectory(bufferLength, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, DynamicLinkCharType*>(bufferLength, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
