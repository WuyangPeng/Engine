///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 16:39)

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