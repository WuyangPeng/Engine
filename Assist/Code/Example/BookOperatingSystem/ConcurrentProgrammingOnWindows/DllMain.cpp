///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ConcurrentProgrammingOnWindows/ConcurrentProgrammingOnWindowsExport.h"

#include "ConcurrentProgrammingOnWindowsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC

DLL_MAIN_FUNCTION(ConcurrentProgrammingOnWindows);

#else  // !BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC

CORE_TOOLS_MUTEX_INIT(ConcurrentProgrammingOnWindows);

#endif  // BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC
