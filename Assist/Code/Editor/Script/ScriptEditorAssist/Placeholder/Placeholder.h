///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:50)

#ifndef SCRIPT_EDITOR_PLACEHOLDER_H
#define SCRIPT_EDITOR_PLACEHOLDER_H

#include "Editor/Script/ScriptEditorAssist/ScriptEditorAssistDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ScriptEditorAssist
{
    class SCRIPT_EDITOR_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCRIPT_EDITOR_PLACEHOLDER_H
