///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 16:20)

#ifndef LEVEL_EDITOR_PLACEHOLDER_H
#define LEVEL_EDITOR_PLACEHOLDER_H

#include "Editor/Level/LevelEditorAssist/LevelEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace LevelEditorAssist
{
    class LEVEL_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // LEVEL_EDITOR_PLACEHOLDER_H
