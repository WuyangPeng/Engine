///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/15 14:31)

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistFwd.h"

#ifndef BUILDING_TERRAIN_EDITOR_STATIC

DLL_MAIN_FUNCTION(TerrainEditorAssist);

#else  // !BUILDING_TERRAIN_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(TerrainEditorAssist);

#endif  // BUILDING_TERRAIN_EDITOR_STATIC
