///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/29 15:02)

#include "Script/ScriptExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Script/ScriptFwd.h"

#ifndef BUILDING_SCRIPT_STATIC

DLL_MAIN_FUNCTION(Script);

#else  // !BUILDING_SCRIPT_STATIC

CORE_TOOLS_MUTEX_INIT(Script);

#endif  // !BUILDING_SCRIPT_STATIC