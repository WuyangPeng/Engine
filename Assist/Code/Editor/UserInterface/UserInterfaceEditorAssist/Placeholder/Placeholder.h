///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 14:40)

#ifndef USER_INTERFACE_EDITOR_PLACEHOLDER_H
#define USER_INTERFACE_EDITOR_PLACEHOLDER_H

#include "Editor/UserInterface/UserInterfaceEditorAssist/UserInterfaceEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace UserInterfaceEditorAssist
{
    class USER_INTERFACE_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // USER_INTERFACE_EDITOR_PLACEHOLDER_H