///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/09 19:03)

#ifndef SHADOW_EDITOR_PLACEHOLDER_H
#define SHADOW_EDITOR_PLACEHOLDER_H

#include "Editor/Shadow/ShadowEditorAssist/ShadowEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ShadowEditorAssist
{
    class SHADOW_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SHADOW_EDITOR_PLACEHOLDER_H
