///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 11:18)

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistExport.h"

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssist.h"

#ifndef BUILDING_TERRAIN_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_TERRAIN_EDITOR_STATIC

namespace TerrainEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_TERRAIN_EDITOR_STATIC
