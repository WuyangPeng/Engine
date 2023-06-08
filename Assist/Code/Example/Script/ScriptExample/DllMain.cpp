///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.11 (2023/05/29 15:34)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Script/ScriptExample/ScriptExampleFwd.h"

#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ScriptExample);

#else  // !BUILDING_SCRIPT_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ScriptExample);

#endif  // !BUILDING_SCRIPT_EXAMPLE_STATIC
