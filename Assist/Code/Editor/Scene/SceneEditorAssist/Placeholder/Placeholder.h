///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:14)

#ifndef SCENE_EDITOR_PLACEHOLDER_H
#define SCENE_EDITOR_PLACEHOLDER_H

#include "Editor/Scene/SceneEditorAssist/SceneEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SceneEditorAssist
{
    class SCENE_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCENE_EDITOR_PLACEHOLDER_H
