///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/20 14:20)

#include "Rendering/RenderingExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Rendering/RenderingFwd.h"

#ifndef BUILDING_RENDERING_STATIC

DLL_MAIN_FUNCTION(Rendering);

#else  // !BUILDING_RENDERING_STATIC

CORE_TOOLS_MUTEX_INIT(Rendering);

#endif  // !BUILDING_RENDERING_STATIC