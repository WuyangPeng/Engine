///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 10:27)

#ifndef ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H
#define ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AssistToolsExample
{
    class ASSIST_TOOLS_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ASSIST_TOOLS_EXAMPLE_PLACEHOLDER_H
