///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/10 13:01)

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
