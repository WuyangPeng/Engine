///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 11:34)

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
        [[nodiscard]] const Matrix3 GeOrthogonalMatrix() const noexcept;
        [[nodiscard]] const Matrix3 GetSymmetryMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 m_Orthogonal;
        Matrix3 m_Symmetry;
    };

    using FloatPolarDecompositionValue = PolarDecompositionValue<float>;
    using DoublePolarDecompositionValue = PolarDecompositionValue<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
