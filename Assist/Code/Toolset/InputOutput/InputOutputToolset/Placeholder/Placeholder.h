///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:43)

#ifndef INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H
#define INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace InputOutputToolset
{
    class INPUT_OUTPUT_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // INPUT_OUTPUT_TOOLSET_PLACEHOLDER_H
