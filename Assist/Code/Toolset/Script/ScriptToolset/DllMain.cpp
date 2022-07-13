///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 16:36)

#include "Toolset/Script/ScriptToolset/ScriptToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Script/ScriptToolset/ScriptToolsetFwd.h"

#ifndef BUILDING_SCRIPT_STATIC

DLL_MAIN_FUNCTION(Script);

#else  // !BUILDING_SCRIPT_STATIC

CORE_TOOLS_MUTEX_INIT(Script);

#endif  // !BUILDING_SCRIPT_STATIC
