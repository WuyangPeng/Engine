///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 15:45)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_DIVIDE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class PolynomialDivide final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

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
