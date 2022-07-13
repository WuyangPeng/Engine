///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 11:19)

#ifndef TERRAIN_EDITOR_PLACEHOLDER_H
#define TERRAIN_EDITOR_PLACEHOLDER_H

#include "Editor/Terrain/TerrainEditorAssist/TerrainEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace TerrainEditorAssist
{
    class TERRAIN_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // TERRAIN_EDITOR_PLACEHOLDER_H
