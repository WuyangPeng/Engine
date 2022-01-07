///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 20:53)

#include "Example/BookOperatingSystem/BeginningLinuxProgramming/BeginningLinuxProgrammingExport.h"

#include "BeginningLinuxProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(BeginningLinuxProgramming);

#else  // !BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(BeginningLinuxProgramming);

#endif  // BUILDING_BEGINNING_LINUX_PROGRAMMING_STATIC
