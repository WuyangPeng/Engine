// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/15 21:43)

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistExport.h"

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SCENE_EDITOR_STATIC

	DLL_MAIN_FUNCTION(SceneEditorAssist);

#else // !BUILDING_SCENE_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(SceneEditorAssist);

#endif // BUILDING_SCENE_EDITOR_STATIC
