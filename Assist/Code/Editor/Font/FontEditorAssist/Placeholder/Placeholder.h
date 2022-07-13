///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/07 11:18)

#ifndef FONT_EDITOR_PLACEHOLDER_H
#define FONT_EDITOR_PLACEHOLDER_H

#include "Editor/Font/FontEditorAssist/FontEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace FontEditorAssist
{
    class FONT_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // FONT_EDITOR_PLACEHOLDER_H
