///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:33)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2EigenDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix2EigenDecomposition<Real>;
        using Matrix2 = Matrix2<Real>;
        using Math = Math<Real>;

    public:
        Matrix2EigenDecomposition(const Matrix2& rotation, const Matrix2& diagonal, const Real epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix2 GetRotation() const noexcept;
        NODISCARD Matrix2 GetDiagonal() const noexcept;

    private:
        Matrix2 rotation;
        Matrix2 diagonal;
        Real epsilon;
    };

    using Matrix2EigenDecompositionF = Matrix2EigenDecomposition<float>;
    using Matrix2EigenDecompositionD = Matrix2EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
