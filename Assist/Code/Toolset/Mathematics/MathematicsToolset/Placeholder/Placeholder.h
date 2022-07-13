///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 11:49)

#ifndef MATHEMATICS_TOOLSET_PLACEHOLDER_H
#define MATHEMATICS_TOOLSET_PLACEHOLDER_H

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MathematicsToolset
{
    class MATHEMATICS_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MATHEMATICS_TOOLSET_PLACEHOLDER_H
