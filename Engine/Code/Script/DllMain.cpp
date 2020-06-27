// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/17 10:47)

#include "Script/ScriptExport.h"

#include "Script/ScriptFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCRIPT_STATIC

DLL_MAIN_FUNCTION(Script);

#else // !BUILDING_SCRIPT_STATIC

CORE_TOOLS_MUTEX_INIT(Script);

#endif // !BUILDING_SCRIPT_STATIC