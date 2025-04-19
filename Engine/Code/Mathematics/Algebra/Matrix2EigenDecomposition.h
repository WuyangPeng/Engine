///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:45)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2EigenDecomposition final
    {
    public:
        using ClassType = Matrix2EigenDecomposition<Real>;

        using Matrix2Type = Matrix2<Real>;
        using MathType = Math<Real>;

    public:
        Matrix2EigenDecomposition(const Matrix2Type& rotation, const Matrix2Type& diagonal, Real epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix2Type GetRotation() const noexcept;
        NODISCARD Matrix2Type GetDiagonal() const noexcept;

    private:
        Matrix2Type rotation;
        Matrix2Type diagonal;
        Real epsilon;
    };

    using Matrix2EigenDecompositionF = Matrix2EigenDecomposition<float>;
    using Matrix2EigenDecompositionD = Matrix2EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
