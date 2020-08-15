//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/16 1:47)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

	DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else  // !BUILDING_STATIC

	CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif  // BUILDING_STATIC