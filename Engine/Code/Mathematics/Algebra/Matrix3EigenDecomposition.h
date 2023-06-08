///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 16:49)

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
        using Matrix3 = Matrix3<Real>;
        using Math = Math<Real>;

    public:
        Matrix3EigenDecomposition(const Matrix3& rotation, const Matrix3& diagonal, Real epsilon) noexcept;

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
