///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/27 19:44)

#include "Example/BookCpp/SamsTeachYourselfCppInOneHourADay/SamsTeachYourselfCppInOneHourADayExport.h"

#include "SamsTeachYourselfCppInOneHourADayFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

DLL_MAIN_FUNCTION(SamsTeachYourselfCppInOneHourADay);

#else  // BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC

CORE_TOOLS_MUTEX_INIT(SamsTeachYourselfCppInOneHourADay);

#endif  // !BUILDING_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_STATIC
