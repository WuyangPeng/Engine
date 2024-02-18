/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 10:58)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class PolynomialDivide final
    {
    public:
        using ClassType = PolynomialDivide<Real>;

        using Polynomial = Polynomial<Real>;

    public:
        PolynomialDivide(Polynomial quotient, Polynomial remainder) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Polynomial GetQuotient() const;
        NODISCARD Polynomial GetRemainder() const;

    private:
        Polynomial quotient;
        Polynomial remainder;
    };

    using PolynomialDivideF = PolynomialDivide<float>;
    using PolynomialDivideD = PolynomialDivide<double>;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
