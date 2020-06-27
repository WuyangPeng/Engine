// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.0 (2020/05/11 21:28)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC	

	DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);	 

#else // !BUILDING_STATIC

	CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif // BUILDING_STATIC
