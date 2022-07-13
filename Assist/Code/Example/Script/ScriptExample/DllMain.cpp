///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 18:28)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Script/ScriptExample/ScriptExampleFwd.h"

#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ScriptExample);

#else  // !BUILDING_SCRIPT_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ScriptExample);

#endif  // !BUILDING_SCRIPT_EXAMPLE_STATIC
