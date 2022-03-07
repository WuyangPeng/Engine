///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 11:46)

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
        NODISCARD Matrix3 GeOrthogonalMatrix() const noexcept;
        NODISCARD Matrix3 GetDiagonalMatrix() const noexcept;
        NODISCARD Matrix3 GetUpperTriangularMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 orthogonal;
        Matrix3 diagonal;
        Matrix3 upperTriangular;
    };

    using QDUDecompositionValueF = QDUDecompositionValue<float>;
    using QDUDecompositionValueD = QDUDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_H
