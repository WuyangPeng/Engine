///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:09)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Rendering/RenderingExample/RenderingExampleFwd.h"

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(RenderingExample);

#else  // !BUILDING_RENDERING_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(RenderingExample);

#endif  // !BUILDING_RENDERING_EXAMPLE_STATIC
