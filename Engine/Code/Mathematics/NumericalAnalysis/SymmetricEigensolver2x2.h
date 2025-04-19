/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SymmetricEigensolver2x2
    {
    public:
        using ClassType = SymmetricEigensolver2x2<Real>;

        using MathType = Math<Real>;

    public:
        SymmetricEigensolver2x2() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入矩阵必须对称，因此只能指定唯一元素：a00, a01和a11。
        ///
        /// 特征值的顺序由sortType指定：-1（递减）、0（无排序）或+1（递增）。
        /// 当排序时，特征向量被相应地排序，并且{evec[0], evec[1]}被保证是右手正交集。

        void operator()(Real a00,
                        Real a01,
                        Real a11,
                        int sortType,
                        std::array<Real, 2>& eval,
                        std::array<std::array<Real, 2>, 2>& evec) const;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_H
