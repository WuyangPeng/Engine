/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValue final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValue<Real>;

        using Matrix3Type = Matrix3<Real>;

    public:
        explicit SingularValue(const Matrix3Type& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD Matrix3Type GetLeftMatrix() const noexcept;
        NODISCARD Matrix3Type GetDiagonalMatrix() const noexcept;
        NODISCARD Matrix3Type GetRightTransposeMatrix() const noexcept;

    private:
        void Calculate(const Matrix3Type& matrix);

    private:
        Matrix3Type left;
        Matrix3Type diagonal;
        Matrix3Type rightTranspose;
    };

    using SingularValueF = SingularValue<float>;
    using SingularValueD = SingularValue<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
