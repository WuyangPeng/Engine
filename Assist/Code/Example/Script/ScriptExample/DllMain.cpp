// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/24 19:30)

#include "Example/Script/ScriptExample/ScriptExampleExport.h"

#include "Example/Script/ScriptExample/ScriptExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ScriptExample);

#else // !BUILDING_SCRIPT_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ScriptExample);

#endif // !BUILDING_SCRIPT_EXAMPLE_STATIC
