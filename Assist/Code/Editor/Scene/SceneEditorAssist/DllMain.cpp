///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:53)

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistFwd.h"

#ifndef BUILDING_SCENE_EDITOR_STATIC

DLL_MAIN_FUNCTION(SceneEditorAssist);

#else  // !BUILDING_SCENE_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(SceneEditorAssist);

#endif  // BUILDING_SCENE_EDITOR_STATIC
