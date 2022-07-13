///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 17:59)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Rendering/RenderingExample/RenderingExampleFwd.h"

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(RenderingExample);

#else  // !BUILDING_RENDERING_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(RenderingExample);

#endif  // !BUILDING_RENDERING_EXAMPLE_STATIC
