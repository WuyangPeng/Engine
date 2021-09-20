// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/21 21:01)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

	DLL_MAIN_FUNCTION(LevelEditorAssist);

#else // !BUILDING_LEVEL_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(LevelEditorAssist);

#endif // BUILDING_LEVEL_EDITOR_STATIC
