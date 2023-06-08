///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:44)

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
