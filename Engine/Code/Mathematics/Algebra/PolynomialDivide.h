///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 17:21)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

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
        PolynomialDivide(const Polynomial& quotient, const Polynomial& remainder);

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
