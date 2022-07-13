///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 17:59)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Rendering/RenderingExample/RenderingExampleFwd.h"

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(RenderingExample);

#else  // !BUILDING_RENDERING_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(RenderingExample);

#endif  // !BUILDING_RENDERING_EXAMPLE_STATIC
