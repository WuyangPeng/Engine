///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 17:07)

#include "Example/Imagics/ImagicsExample/ImagicsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Imagics/ImagicsExample/ImagicsExampleFwd.h"

#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ImagicsExample);

#else  // !BUILDING_IMAGICS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ImagicsExample);

#endif  // !BUILDING_IMAGICS_EXAMPLE_STATIC
