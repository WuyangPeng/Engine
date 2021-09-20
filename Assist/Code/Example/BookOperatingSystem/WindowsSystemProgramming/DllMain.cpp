///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/12 16:54)

#include "Example/BookOperatingSystem/WindowsSystemProgramming/WindowsSystemProgrammingExport.h"

#include "WindowsSystemProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(WindowsSystemProgramming);

#else  // !BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(WindowsSystemProgramming);

#endif  // BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC
