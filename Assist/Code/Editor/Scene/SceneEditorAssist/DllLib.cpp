///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 14:33)

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistExport.h"

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssist.h"

#ifndef BUILDING_SCENE_EDITOR_STATIC

    #include "DllLib.h"

#else  // BUILDING_SCENE_EDITOR_STATIC

namespace SceneEditorAssist
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SCENE_EDITOR_STATIC
