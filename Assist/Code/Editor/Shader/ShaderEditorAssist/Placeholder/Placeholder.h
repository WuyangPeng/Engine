///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/09 17:47)

#ifndef SHADER_EDITOR_PLACEHOLDER_H
#define SHADER_EDITOR_PLACEHOLDER_H

#include "Editor/Shader/ShaderEditorAssist/ShaderEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ShaderEditorAssist
{
    class SHADER_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SHADER_EDITOR_PLACEHOLDER_H
