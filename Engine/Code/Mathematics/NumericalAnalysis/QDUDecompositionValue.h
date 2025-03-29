/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

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

        using Matrix3Type = Matrix3<Real>;
        using MathType = Math<Real>;

    public:
        explicit QDUDecompositionValue(const Matrix3Type& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD Matrix3Type GeOrthogonalMatrix() const noexcept;
        NODISCARD Matrix3Type GetDiagonalMatrix() const noexcept;
        NODISCARD Matrix3Type GetUpperTriangularMatrix() const noexcept;

    private:
        void Calculate(const Matrix3Type& matrix);

    private:
        Matrix3Type orthogonal;
        Matrix3Type diagonal;
        Matrix3Type upperTriangular;
    };

    using QDUDecompositionValueF = QDUDecompositionValue<float>;
    using QDUDecompositionValueD = QDUDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H
