// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/26 1:14)

#include "Example/Rendering/RenderingExample/RenderingExampleExport.h"

#include "Example/Rendering/RenderingExample/RenderingExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(RenderingExample);

#else // !BUILDING_RENDERING_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(RenderingExample);

#endif // !BUILDING_RENDERING_EXAMPLE_STATIC
