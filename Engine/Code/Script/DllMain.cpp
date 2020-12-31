//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 14:34)

#include "Script/ScriptExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Script/ScriptFwd.h"

#ifndef BUILDING_SCRIPT_STATIC

DLL_MAIN_FUNCTION(Script);

#else  // !BUILDING_SCRIPT_STATIC

CORE_TOOLS_MUTEX_INIT(Script);

#endif  // !BUILDING_SCRIPT_STATIC