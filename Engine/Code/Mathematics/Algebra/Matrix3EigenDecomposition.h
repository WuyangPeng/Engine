///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:54)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3EigenDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3EigenDecomposition<Real>;
        using Matrix3 = Matrix3<Real>;
        using Math = Math<Real>;

    public:
        Matrix3EigenDecomposition(const Matrix3& rotation, const Matrix3& diagonal, const Real epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix3 GetRotation() const noexcept;
        NODISCARD Matrix3 GetDiagonal() const noexcept;

    private:
        Matrix3 rotation;
        Matrix3 diagonal;
        Real epsilon;
    };

    using Matrix3EigenDecompositionF = Matrix3EigenDecomposition<float>;
    using Matrix3EigenDecompositionD = Matrix3EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
