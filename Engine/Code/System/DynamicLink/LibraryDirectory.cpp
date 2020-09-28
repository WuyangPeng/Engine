//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:08)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/WindowsMacro.h"

bool System::SetLibraryDirectory([[maybe_unused]] const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetDllDirectory(pathName) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetLibraryDirectory([[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] DynamicLinkCharType* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetDllDirectory(bufferLength, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
