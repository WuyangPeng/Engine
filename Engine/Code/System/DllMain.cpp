///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:17)

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