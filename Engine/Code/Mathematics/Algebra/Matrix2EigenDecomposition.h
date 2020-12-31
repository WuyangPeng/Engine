///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 14:05)

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

        [[nodiscard]] const Matrix2 GetRotation() const noexcept;
        [[nodiscard]] const Matrix2 GetDiagonal() const noexcept;

    private:
        Matrix2 m_Rotation;
        Matrix2 m_Diagonal;
        Real m_Epsilon;
    };

    using FloatMatrix2EigenDecomposition = Matrix2EigenDecomposition<float>;
    using DoubleMatrix2EigenDecomposition = Matrix2EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
