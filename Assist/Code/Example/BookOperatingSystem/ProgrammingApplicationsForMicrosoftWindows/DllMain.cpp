///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/08 21:39)

#include "Example/BookOperatingSystem/ProgrammingApplicationsForMicrosoftWindows/ProgrammingApplicationsForMicrosoftWindowsExport.h"

#include "ProgrammingApplicationsForMicrosoftWindowsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

DLL_MAIN_FUNCTION(ProgrammingApplicationsForMicrosoftWindows);

#else  // !BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

CORE_TOOLS_MUTEX_INIT(ProgrammingApplicationsForMicrosoftWindows);

#endif  // BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC
