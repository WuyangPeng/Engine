/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/22 10:01)

#include "Rendering/RenderingExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Rendering/RenderingFwd.h"

#ifndef BUILDING_RENDERING_STATIC

DLL_MAIN_FUNCTION(Rendering);

#else  // !BUILDING_RENDERING_STATIC

CORE_TOOLS_MUTEX_INIT(Rendering);

#endif  // !BUILDING_RENDERING_STATIC