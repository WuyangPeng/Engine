///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/ProfessionalMulticoreProgramming/ProfessionalMulticoreProgrammingExport.h"

#include "ProfessionalMulticoreProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(ProfessionalMulticoreProgramming);

#else  // !BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(ProfessionalMulticoreProgramming);

#endif  // BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC
