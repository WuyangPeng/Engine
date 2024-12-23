/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/12 09:58)

#include "ThreadingCoreRenderEngineExport.h"

#include "ThreadingCoreRenderEngineFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STATIC

DLL_MAIN_FUNCTION(ThreadingCoreRenderEngine);

#else  // !BUILDING_STATIC

CORE_TOOLS_MUTEX_INIT(ThreadingCoreRenderEngine);

#endif  // BUILDING_STATIC