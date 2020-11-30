///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 10:08)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "PolynomialDivideDetail.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/PolynomialDivide.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class PolynomialImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<PolynomialImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polynomial final : private boost::additive<Polynomial<Real>, boost::additive<Polynomial<Real>, Real, boost::multiplicative<Polynomial<Real>, Real>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using PolynomialImpl = PolynomialImpl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Polynomial, DESTRUCTOR_DEFAULT);
        using PolynomialDivide = PolynomialDivide<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;

    public:
        explicit Polynomial(int degree = 0);
        explicit Polynomial(const ContainerType& coeff);

        CLASS_INVARIANT_DECLARE;

        // 成员访问

        // 重新设置会清空旧数据。
        void ResetDegree(int degree);

        [[nodiscard]] int GetDegree() const;
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);
        [[nodiscard]] Real GetBegin() const noexcept;
        [[nodiscard]] Real GetEnd() const noexcept;

        // 计算多项式，p(t)。
        [[nodiscard]] Real operator()(Real value) const;

        [[nodiscard]] ContainerType GetValue() const;
        void SetValue(const ContainerType& coeff);

        [[nodiscard]] const Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar);  // 输入是零阶的多项式
        Polynomial& operator-=(Real scalar);  // 输入是零阶的多项式
        Polynomial& operator*=(Real scalar);
        Polynomial& operator/=(Real scalar);

        // 计算多项式的导数。
        [[nodiscard]] const Polynomial GetDerivative() const;

        // 反转( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        [[nodiscard]] const Polynomial GetInversion() const;

        // 通过消除所有的（接近）零的系数和使主导系数减少1阶。
        // 输入参数是阈值，用于指定一个系数实际上为零。
        void Compress(Real epsilon);

        // 如果'this'为P（t）和除数（divisor）为D(t)使degree(P) >= degree(D)，
        // 则P(t) = Q(t) * D(t) + Real(t) 其中Q(t)是quotient
        // 使degree(Q) = degree(P) - degree(D)和Real(t)是remainder使
        // degree(Real) < degree(D)。 如果Q = 0 和 Real = P则返回
        // 值epsilon被用作剩余多项式系统的阈值。
        // 如果比epsilon小，则系数被假设为零。
        // 返回值第一个部分为quotient，第二部分为remainder。
        [[nodiscard]] const PolynomialDivide Divide(const Polynomial& divisor, Real epsilon) const;

    private:
        IMPL_TYPE_DECLARE(Polynomial);
    };

    template <typename Real>
    [[nodiscard]] const Polynomial<Real> operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename T>
    [[nodiscard]] bool Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, const T epsilon = Math<Real>::GetZeroTolerance());

    using FloatPolynomial = Polynomial<float>;
    using DoublePolynomial = Polynomial<double>;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_H
