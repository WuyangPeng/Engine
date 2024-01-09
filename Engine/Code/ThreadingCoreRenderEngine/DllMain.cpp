/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 11:21)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else  // !BUILDING_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif  // BUILDING_STATIC