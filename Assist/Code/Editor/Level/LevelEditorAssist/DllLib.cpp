///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:33)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "Editor/Level/LevelEditorAssist/LevelEditorAssist.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_LEVEL_EDITOR_STATIC

namespace LevelEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_LEVEL_EDITOR_STATIC
