///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:25)

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
