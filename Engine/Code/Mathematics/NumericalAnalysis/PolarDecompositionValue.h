///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 11:43)

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
        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;

    public:
        explicit PolarDecompositionValue(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD Matrix3 GeOrthogonalMatrix() const noexcept;
        NODISCARD Matrix3 GetSymmetryMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 orthogonal;
        Matrix3 symmetry;
    };

    using PolarDecompositionValueF = PolarDecompositionValue<float>;
    using PolarDecompositionValueD = PolarDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
