/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:44)

#ifndef CORE_TOOLS_EXAMPLE_PLACEHOLDER_H
#define CORE_TOOLS_EXAMPLE_PLACEHOLDER_H

#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreToolsExample
{
    class CORE_TOOLS_EXAMPLE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CORE_TOOLS_EXAMPLE_PLACEHOLDER_H
