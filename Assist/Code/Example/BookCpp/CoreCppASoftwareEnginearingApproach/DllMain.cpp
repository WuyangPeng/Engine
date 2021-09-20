///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 13:04)

#include "Example/BookCpp/CoreCppASoftwareEnginearingApproach/CoreCppASoftwareEnginearingApproachExport.h"

#include "CoreCppASoftwareEnginearingApproachFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC

DLL_MAIN_FUNCTION(CoreCppASoftwareEnginearingApproach);

#else  // BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC

CORE_TOOLS_MUTEX_INIT(CoreCppASoftwareEnginearingApproach);

#endif  // !BUILDING_CORE_CPP_A_SOFTWARE_ENGINEARING_APPROACH_STATIC
