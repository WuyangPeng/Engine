///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 14:34)

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
