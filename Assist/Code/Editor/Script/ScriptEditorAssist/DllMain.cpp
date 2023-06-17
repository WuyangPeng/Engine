///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:08)

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistFwd.h"

#ifndef BUILDING_SCRIPT_EDITOR_STATIC

DLL_MAIN_FUNCTION(ScriptEditorAssist);

#else  // !BUILDING_SCRIPT_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(ScriptEditorAssist);

#endif  // BUILDING_SCRIPT_EDITOR_STATIC
