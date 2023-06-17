///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 14:58)

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
