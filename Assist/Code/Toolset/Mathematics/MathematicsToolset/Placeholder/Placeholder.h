///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/09 10:34)

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
