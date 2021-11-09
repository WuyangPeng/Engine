///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/MultithreadingApplicationsInWin32/MultithreadingApplicationsInWin32Export.h"

#include "MultithreadingApplicationsInWin32.h"

#ifndef BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

namespace MultithreadingApplicationsInWin32
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC
