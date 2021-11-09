///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/AdvancedWindowsDebugging/AdvancedWindowsDebuggingExport.h"

#include "AdvancedWindowsDebugging.h"

#ifndef BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

namespace AdvancedWindowsDebugging
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC
