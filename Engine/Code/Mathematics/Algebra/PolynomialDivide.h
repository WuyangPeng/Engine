///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 13:01)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE PolynomialDivide final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialDivide<Real>;
        using Polynomial = Polynomial<Real>;

    public:
        PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Polynomial GetQuotient() const;
        [[nodiscard]] const Polynomial GetRemainder() const;

    private:
        Polynomial m_Quotient;
        Polynomial m_Remainder;
    };

    using PolynomialDividef = PolynomialDivide<float>;
    using PolynomialDivided = PolynomialDivide<double>;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
