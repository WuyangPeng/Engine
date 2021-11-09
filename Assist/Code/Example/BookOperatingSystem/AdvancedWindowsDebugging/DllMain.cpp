///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/AdvancedWindowsDebugging/AdvancedWindowsDebuggingExport.h"

#include "AdvancedWindowsDebuggingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

DLL_MAIN_FUNCTION(AdvancedWindowsDebugging);

#else  // !BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedWindowsDebugging);

#endif  // BUILDING_ADVANCED_WINDOWS_DEBUGGING_STATIC
