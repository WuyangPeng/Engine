// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2019/12/30 10:16)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

	DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else // !BUILDING_STATIC

	CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif // BUILDING_STATIC

