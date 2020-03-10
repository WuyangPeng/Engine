// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 13:23)

#include "Script/ScriptExport.h"

#include "Script/ScriptFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCRIPT_STATIC

	DLL_MAIN_FUNCTION(Script);

#else // !BUILDING_SCRIPT_STATIC

	CORE_TOOLS_MUTEX_INIT(Script);

#endif // !BUILDING_SCRIPT_STATIC