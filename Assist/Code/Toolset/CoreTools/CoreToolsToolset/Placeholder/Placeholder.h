///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:33)

#ifndef CORE_TOOLS_TOOLSET_PLACEHOLDER_H
#define CORE_TOOLS_TOOLSET_PLACEHOLDER_H

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CoreToolsToolset
{
    class CORE_TOOLS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CORE_TOOLS_TOOLSET_PLACEHOLDER_H
