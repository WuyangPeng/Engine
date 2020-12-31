///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 9:45)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE PolynomialImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = PolynomialImpl<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        explicit PolynomialImpl(int degree = 0);
        explicit PolynomialImpl(const ContainerType& coeff);

        CLASS_INVARIANT_DECLARE;

        // 重新设置会清空旧数据。
        void ResetDegree(int degree);

        [[nodiscard]] int GetDegree() const;

        [[nodiscard]] ContainerType GetValue() const;
        void SetValue(const ContainerType& coeff);

        [[nodiscard]] ContainerTypeConstIter begin() const noexcept;
        [[nodiscard]] ContainerTypeConstIter end() const noexcept;

        [[nodiscard]] ContainerTypeIter begin() noexcept;
        [[nodiscard]] ContainerTypeIter end() noexcept;

        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);

        [[nodiscard]] Real GetBegin() const noexcept;
        [[nodiscard]] Real GetEnd() const noexcept;

        [[nodiscard]] Real operator()(Real value) const;

        void Negative() noexcept;
        void Plus(const PolynomialImpl& rhs);
        void Minus(const PolynomialImpl& rhs);
        int GetCompressDegree(Real epsilon) const;

    private:
        ContainerType m_Coeff;
    };
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_IMPL_H
