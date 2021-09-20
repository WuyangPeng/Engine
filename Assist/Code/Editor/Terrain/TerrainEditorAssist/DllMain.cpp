// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/13 21:00)

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistExport.h"

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_TERRAIN_EDITOR_STATIC

	DLL_MAIN_FUNCTION(TerrainEditorAssist);

#else // !BUILDING_TERRAIN_EDITOR_STATIC

	CORE_TOOLS_MUTEX_INIT(TerrainEditorAssist);

#endif // BUILDING_TERRAIN_EDITOR_STATIC
