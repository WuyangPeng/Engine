///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:45)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3EigenDecomposition final
    {
    public:
        using ClassType = Matrix3EigenDecomposition<Real>;

        using Matrix3Type = Matrix3<Real>;
        using MathType = Math<Real>;

    public:
        Matrix3EigenDecomposition(const Matrix3Type& rotation, const Matrix3Type& diagonal, Real epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix3Type GetRotation() const noexcept;
        NODISCARD Matrix3Type GetDiagonal() const noexcept;

    private:
        Matrix3Type rotation;
        Matrix3Type diagonal;
        Real epsilon;
    };

    using Matrix3EigenDecompositionF = Matrix3EigenDecomposition<float>;
    using Matrix3EigenDecompositionD = Matrix3EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
