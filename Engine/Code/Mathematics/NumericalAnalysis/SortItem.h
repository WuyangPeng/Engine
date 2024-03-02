///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 11:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    /// 计算排序引起的排列。
    /// 首先，我们从恒等置换I = (0,1,...,N-1)开始。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SortItem
    {
    public:
        using ClassType = SortItem<Real>;

    public:
        SortItem() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetEigenvalue() const noexcept;

        void SetEigenvalue(Real aEigenvalue) noexcept;

        NODISCARD int GetIndex() const noexcept;

        void SetIndex(int aIndex) noexcept;

    private:
        Real eigenvalue;
        int index;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_H
