///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 16:36)

#include "Toolset/Script/ScriptToolset/ScriptToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Script/ScriptToolset/ScriptToolsetFwd.h"

#ifndef BUILDING_SCRIPT_STATIC

DLL_MAIN_FUNCTION(Script);

#else  // !BUILDING_SCRIPT_STATIC

CORE_TOOLS_MUTEX_INIT(Script);

#endif  // !BUILDING_SCRIPT_STATIC
