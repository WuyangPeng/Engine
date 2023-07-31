///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:49)

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistFwd.h"

#ifndef BUILDING_SCRIPT_EDITOR_STATIC

DLL_MAIN_FUNCTION(ScriptEditorAssist);

#else  // !BUILDING_SCRIPT_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ScriptEditorAssist);

#endif  // BUILDING_SCRIPT_EDITOR_STATIC
