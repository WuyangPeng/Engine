///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 18:28)

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

        [[nodiscard]] const Matrix3 GetRotation() const noexcept;
        [[nodiscard]] const Matrix3 GetDiagonal() const noexcept;

    private:
        Matrix3 m_Rotation;
        Matrix3 m_Diagonal;
        Real m_Epsilon;
    };

    using FloatMatrix3EigenDecomposition = Matrix3EigenDecomposition<float>;
    using DoubleMatrix3EigenDecomposition = Matrix3EigenDecomposition<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
