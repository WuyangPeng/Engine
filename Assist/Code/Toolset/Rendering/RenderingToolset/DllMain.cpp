///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 14:31)

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Rendering/RenderingToolset/RenderingToolsetFwd.h"

#ifndef BUILDING_RENDERING_STATIC

DLL_MAIN_FUNCTION(Rendering);

#else  // !BUILDING_RENDERING_STATIC

CORE_TOOLS_MUTEX_INIT(Rendering);

#endif  // !BUILDING_RENDERING_STATIC
