///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ConcurrentProgrammingOnWindows/ConcurrentProgrammingOnWindowsExport.h"

#include "ConcurrentProgrammingOnWindows.h"

#ifndef BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC

namespace ConcurrentProgrammingOnWindows
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC
