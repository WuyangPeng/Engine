/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 15:13)

#include "System/SystemExport.h"

#include "Helper/WindowsMacro.h"
#include "Windows/Using/WindowsUsing.h"
#include "System/SystemFwd.h"

#if !defined(BUILDING_SYSTEM_STATIC) && defined(SYSTEM_PLATFORM_WIN32)

int SYSTEM_WINAPI DllMain(MAYBE_UNUSED System::WindowsHInstance instance,
                          MAYBE_UNUSED System::WindowsDWord reason,
                          MAYBE_UNUSED System::WindowsVoidPtr reserved) noexcept
{
    return System::gTrue;
}

#else  // defined(BUILDING_SYSTEM_STATIC) || !defined(SYSTEM_PLATFORM_WIN32)

namespace System
{
    void SystemDllMain() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_STATIC