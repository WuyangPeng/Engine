///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/25 23:58)

#ifndef BOOK_ALGORITHM_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_ALGORITHM_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/BookAlgorithm/BookAlgorithmDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAlgorithm
{
    class BOOK_ALGORITHM_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_ALGORITHM_PLACEHOLDER_PLACEHOLDER_H
