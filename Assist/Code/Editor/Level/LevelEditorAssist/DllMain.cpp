///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:32)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Level/LevelEditorAssist/LevelEditorAssistFwd.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

DLL_MAIN_FUNCTION(LevelEditorAssist);

#else  // !BUILDING_LEVEL_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(LevelEditorAssist);

#endif  // BUILDING_LEVEL_EDITOR_STATIC
