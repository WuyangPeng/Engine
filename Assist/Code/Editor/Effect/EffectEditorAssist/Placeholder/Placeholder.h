///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 17:22)

#ifndef EFFECT_EDITOR_PLACEHOLDER_H
#define EFFECT_EDITOR_PLACEHOLDER_H

#include "Editor/Effect/EffectEditorAssist/EffectEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace EffectEditorAssist
{
    class EFFECT_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // EFFECT_EDITOR_PLACEHOLDER_H
