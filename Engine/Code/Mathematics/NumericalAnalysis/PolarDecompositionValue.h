/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolarDecompositionValue final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolarDecompositionValue<Real>;

        using MathType = Math<Real>;
        using Matrix3Type = Matrix3<Real>;

    public:
        explicit PolarDecompositionValue(const Matrix3Type& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD Matrix3Type GeOrthogonalMatrix() const noexcept;
        NODISCARD Matrix3Type GetSymmetryMatrix() const noexcept;

    private:
        void Calculate(const Matrix3Type& matrix);

    private:
        Matrix3Type orthogonal;
        Matrix3Type symmetry;
    };

    using PolarDecompositionValueF = PolarDecompositionValue<float>;
    using PolarDecompositionValueD = PolarDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
