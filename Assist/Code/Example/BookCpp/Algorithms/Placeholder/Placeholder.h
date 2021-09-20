///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/28 12:58)

#ifndef ALGORITHMS_PLACEHOLDER_PLACEHOLDER_H
#define ALGORITHMS_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/Algorithms/AlgorithmsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Algorithms
{
    class ALGORITHMS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ALGORITHMS_PLACEHOLDER_PLACEHOLDER_H
