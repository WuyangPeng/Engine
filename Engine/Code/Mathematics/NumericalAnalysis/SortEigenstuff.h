/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SortEigenstuff
    {
    public:
        using ClassType = SortEigenstuff<Real>;

    public:
        SortEigenstuff() noexcept;

        CLASS_INVARIANT_DECLARE;

        void operator()(int sortType,
                        bool isRotation,
                        std::array<Real, 3>& eval,
                        std::array<std::array<Real, 3>, 3>& evec);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_H
