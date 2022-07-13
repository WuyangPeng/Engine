///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 11:18)

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistFwd.h"

#ifndef BUILDING_TERRAIN_EDITOR_STATIC

DLL_MAIN_FUNCTION(TerrainEditorAssist);

#else  // !BUILDING_TERRAIN_EDITOR_STATIC

CORE_TOOLS_MUTEX_INIT(TerrainEditorAssist);

#endif  // BUILDING_TERRAIN_EDITOR_STATIC
