///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/29 20:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QDUDecompositionValue final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = QDUDecompositionValue<Real>;
        using Matrix3 = Matrix3<Real>;
        using Math = Math<Real>;

    public:
        explicit QDUDecompositionValue(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] const Matrix3 GeOrthogonalMatrix() const noexcept;
        [[nodiscard]] const Matrix3 GetDiagonalMatrix() const noexcept;
        [[nodiscard]] const Matrix3 GetUpperTriangularMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 m_Orthogonal;
        Matrix3 m_Diagonal;
        Matrix3 m_UpperTriangular;
    };

    using FloatQDUDecompositionValue = QDUDecompositionValue<float>;
    using DoubleQDUDecompositionValue = QDUDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H
