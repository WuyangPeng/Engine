///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.0 (2021/02/18 22:57)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else  // !BUILDING_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif  // BUILDING_STATIC