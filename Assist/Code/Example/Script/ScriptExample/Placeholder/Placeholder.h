///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.11 (2023/05/29 15:36)

#ifndef SCRIPT_EXAMPLE_PLACEHOLDER_H
#define SCRIPT_EXAMPLE_PLACEHOLDER_H

#include "Example/Script/ScriptExample/ScriptExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ScriptExample
{
    class SCRIPT_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SCRIPT_EXAMPLE_PLACEHOLDER_H
