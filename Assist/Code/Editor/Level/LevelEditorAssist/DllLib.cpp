///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 16:18)

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistExport.h"

#include "Editor/Level/LevelEditorAssist/LevelEditorAssist.h"

#ifndef BUILDING_LEVEL_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_LEVEL_EDITOR_STATIC

namespace LevelEditorAssist
{
    void StaticDllLib()
    {
    }
}

#endif  // !BUILDING_LEVEL_EDITOR_STATIC
