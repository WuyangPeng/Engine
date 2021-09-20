///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/08 21:39)

#include "Example/BookOperatingSystem/ProgrammingApplicationsForMicrosoftWindows/ProgrammingApplicationsForMicrosoftWindowsExport.h"

#include "ProgrammingApplicationsForMicrosoftWindows.h"

#ifndef BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

namespace ProgrammingApplicationsForMicrosoftWindows
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC
