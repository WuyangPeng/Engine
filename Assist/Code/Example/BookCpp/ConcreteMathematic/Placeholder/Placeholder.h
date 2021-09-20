///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:57)

#ifndef CONCRETE_MATHEMATIC_PLACEHOLDER_PLACEHOLDER_H
#define CONCRETE_MATHEMATIC_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/ConcreteMathematic/ConcreteMathematicDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ConcreteMathematic
{
    class CONCRETE_MATHEMATIC_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CONCRETE_MATHEMATIC_PLACEHOLDER_PLACEHOLDER_H
