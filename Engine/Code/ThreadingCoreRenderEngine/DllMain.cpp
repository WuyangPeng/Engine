///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.0 (2021/02/18 22:57)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else  // !BUILDING_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif  // BUILDING_STATIC