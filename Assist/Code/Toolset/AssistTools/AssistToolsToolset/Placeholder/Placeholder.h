///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:37)

#ifndef ASSIST_TOOLS_TOOLSET_PLACEHOLDER_H
#define ASSIST_TOOLS_TOOLSET_PLACEHOLDER_H

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AssistToolsToolset
{
    class ASSIST_TOOLS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ASSIST_TOOLS_TOOLSET_PLACEHOLDER_H
