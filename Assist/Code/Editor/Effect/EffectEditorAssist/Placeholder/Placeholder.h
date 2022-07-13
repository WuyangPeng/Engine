///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/06 17:22)

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
