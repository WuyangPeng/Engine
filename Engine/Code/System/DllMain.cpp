//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/20 14:01)

#include "System/SystemExport.h"

#include "System/SystemFwd.h"

#include "Helper/WindowsMacro.h"
#include "Window/Using/WindowUsing.h"

#if !defined(BUILDING_SYSTEM_STATIC) && defined(SYSTEM_PLATFORM_WIN32)

using System::WindowDWord;
using System::WindowHInstance;
using System::WindowVoidPtr;

int SYSTEM_WINAPI DllMain([[maybe_unused]] WindowHInstance instance, [[maybe_unused]] WindowDWord reason, [[maybe_unused]] WindowVoidPtr reserved) noexcept
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