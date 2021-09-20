///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/01 10:51)

#include "System/SystemExport.h"

#include "System/SystemFwd.h"

#include "Helper/WindowsMacro.h"
#include "Windows/Using/WindowsUsing.h"

#if !defined(BUILDING_SYSTEM_STATIC) && defined(SYSTEM_PLATFORM_WIN32)

using System::WindowsDWord;
using System::WindowsHInstance;
using System::WindowsVoidPtr;

int SYSTEM_WINAPI DllMain(MAYBE_UNUSED WindowsHInstance instance, MAYBE_UNUSED WindowsDWord reason, MAYBE_UNUSED WindowsVoidPtr reserved) noexcept
{
    return System::g_True;
}

#else  // defined(BUILDING_SYSTEM_STATIC) || !defined(SYSTEM_PLATFORM_WIN32)

namespace System
{
    void SystemDllMain() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_STATIC