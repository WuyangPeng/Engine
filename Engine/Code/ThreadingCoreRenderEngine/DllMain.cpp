// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.4.0.0 (2020/07/10 21:39)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC	

	DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);	 

#else // !BUILDING_STATIC

	CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif // BUILDING_STATIC