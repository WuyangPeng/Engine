///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 15:02)

#ifndef MATERIAL_EDITOR_PLACEHOLDER_H
#define MATERIAL_EDITOR_PLACEHOLDER_H

#include "Editor/Material/MaterialEditorAssist/MaterialEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MaterialEditorAssist
{
    class MATERIAL_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MATERIAL_EDITOR_PLACEHOLDER_H
