///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 16:18)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Level/LevelEditorAssist/LevelEditorAssistFwd.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

DLL_MAIN_FUNCTION(LevelEditorAssist);

#else  // !BUILDING_LEVEL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(LevelEditorAssist);

#endif  // BUILDING_LEVEL_EDITOR_STATIC
