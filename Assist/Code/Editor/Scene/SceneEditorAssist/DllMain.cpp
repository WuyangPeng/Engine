///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 14:33)

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistExport.h"

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_EDITOR_STATIC

DLL_MAIN_FUNCTION(SceneEditorAssist);

#else  // !BUILDING_SCENE_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(SceneEditorAssist);

#endif  // BUILDING_SCENE_EDITOR_STATIC
