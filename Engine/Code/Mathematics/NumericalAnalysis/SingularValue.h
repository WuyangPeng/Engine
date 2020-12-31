///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/30 10:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValue final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValue<Real>;
        using Matrix3 = Matrix3<Real>;

    public:
        explicit SingularValue(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] const Matrix3 GetLeftMatrix() const noexcept;
        [[nodiscard]] const Matrix3 GetDiagonalMatrix() const noexcept;
        [[nodiscard]] const Matrix3 GetRightTransposeMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 m_Left;
        Matrix3 m_Diagonal;
        Matrix3 m_RightTranspose;
    };

    using FloatSingularValue = SingularValue<float>;
    using DoubleSingularValue = SingularValue<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
