///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/06 21:21)

#include "Example/BookOperatingSystem/ModernOperatingSystems/ModernOperatingSystemsExport.h"

#include "ModernOperatingSystemsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

DLL_MAIN_FUNCTION(ModernOperatingSystems);

#else  // !BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

CORE_TOOLS_MUTEX_INIT(ModernOperatingSystems);

#endif  // BUILDING_MODERN_OPERATING_SYSTEMS_STATIC
