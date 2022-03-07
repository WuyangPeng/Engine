// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/05 11:57)

#ifndef SCRIPT_TOOLSET_PLACEHOLDER_H
#define SCRIPT_TOOLSET_PLACEHOLDER_H

#include "Toolset/Script/ScriptToolset/ScriptToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ScriptToolset
{
    class SCRIPT_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCRIPT_TOOLSET_PLACEHOLDER_H