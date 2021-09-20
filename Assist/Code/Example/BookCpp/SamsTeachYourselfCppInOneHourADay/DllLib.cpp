///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/27 19:45)

#include "Example/BookCpp/SamsTeachYourselfCppInOneHourADay/SamsTeachYourselfCppInOneHourADayExport.h"

#include "SamsTeachYourselfCppInOneHourADay.h"

#ifndef BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

namespace SamsTeachYourselfCppInOneHourADay
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC
