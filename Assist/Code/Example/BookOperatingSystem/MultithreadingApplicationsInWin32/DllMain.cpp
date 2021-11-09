///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/MultithreadingApplicationsInWin32/MultithreadingApplicationsInWin32Export.h"

#include "MultithreadingApplicationsInWin32Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

DLL_MAIN_FUNCTION(MultithreadingApplicationsInWin32);

#else  // !BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

CORE_TOOLS_MUTEX_INIT(MultithreadingApplicationsInWin32);

#endif  // BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC
