///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:39)

#ifndef EXAMPLE_TOOLSET_PLACEHOLDER_H
#define EXAMPLE_TOOLSET_PLACEHOLDER_H

#include "Toolset/Example/ExampleToolset/ExampleToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ExampleToolset
{
    class EXAMPLE_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // EXAMPLE_TOOLSET_PLACEHOLDER_H
