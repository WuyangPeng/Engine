/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 10:57)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/PolynomialDivide.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Polynomial final : private boost::additive<Polynomial<Real>, boost::additive<Polynomial<Real>, Real, boost::multiplicative<Polynomial<Real>, Real>>>
    {
    public:
        using ClassType = Polynomial<Real>;

        using PolynomialDivide = PolynomialDivide<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;

    public:
        /// 第一个构造函数创建指定次数的多项式，但将所有系数设置为零（以确保初始化）。
        /// 您负责设置系数，大概是将次数项设置为非零值。
        /// 在第二个构造函数中，度是初始化器的数量加1，
        /// 但随后进行调整，使系数[度]不为零（除非所有初始化器值都为零）。
        explicit Polynomial(int degree);
        explicit Polynomial(const ContainerType& coefficient);

        explicit Polynomial(ContainerType&& coefficient) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 支持部分构造，当度未知时使用默认构造函数。系数未初始化。
        void SetDegree(int degree);

        /// 将所有系数设置为指定值。
        void SetCoefficients(Real value);

        /// 成员访问

        NODISCARD int GetDegree() const;

        NODISCARD ContainerType GetCoefficients() const;
        void SetCoefficients(const ContainerType& aCoefficient);
        void SetCoefficients(ContainerType&& aCoefficient);

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetBegin() const noexcept;
        NODISCARD Real GetEnd() const noexcept;

        /// 计算多项式，p(t)。
        /// 如果多项式无效，函数将返回零。
        NODISCARD Real operator()(Real value) const noexcept;

        /// 一元运算。
        NODISCARD Polynomial operator+() const;
        NODISCARD Polynomial operator-() const;

        /// 线性代数运算。
        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator-=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        /// 计算多项式的导数。
        NODISCARD Polynomial GetDerivative() const;

        /// 反转( inv_poly[i] = poly[degree-i] for 0 <= i <= degree ).
        NODISCARD Polynomial GetInversion() const;

        /// 转换.  如果 'this' 是 p(t}, 返回 p(t-t0).
        NODISCARD Polynomial GetTranslation(Real t0) const;

        /// 消除多项式中的任何前导零，除非阶数为0且系数为0。
        /// 当算术运算导致结果的程度降低时，消除是必要的。
        /// 例如，(1 + x + x^2) + (1 + 2*x - x^2) = (2 + 3*x)。
        /// 这两个输入都具有阶数2，因此结果是以阶数2创建的。
        /// 相加后，我们发现阶数实际上是1，并调整系数数组的大小。
        /// 此函数由算术运算符内部调用，
        /// 但它在公共接口中公开，以防您出于自己的目的需要它。
        void EliminateLeadingZeros(Real epsilon);

        /// 通过消除所有的（接近）零的系数和使主导系数减少1阶。
        /// 输入参数是阈值，用于指定一个系数实际上为零。
        void MakeCompress(Real epsilon);

        /// 如果'this'为P(t)和除数(divisor)为D(t)，使degree(P) >= degree(D)，
        /// 则P(t) = Q(t) * D(t) + R(t) 其中Q(t)是quotient
        /// 使degree(Q) = degree(P) - degree(D)和R(t)是remainder使
        /// degree(R) < degree(D)。 如果Q = 0 和 R = P则返回。
        /// 值epsilon被用作剩余多项式系统的阈值。
        /// 如果比epsilon小，则系数被假设为零。
        /// 返回值第一个部分为quotient，第二部分为remainder。
        NODISCARD PolynomialDivide Divide(const Polynomial& divisor, Real epsilon) const;

        NODISCARD bool Equal(const Polynomial& rhs) const;
        NODISCARD bool Less(const Polynomial& rhs) const;

    private:
        NODISCARD int GetCompressDegree(Real epsilon) const;

    private:
        /// 该类的设计使coefficient.size() >= 1。
        ContainerType coefficient;
    };

    /// 比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD Polynomial<Real> operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    /// 计算两个多项式的最大公约数。
    /// 返回的多项式具有前导系数1（零值多项式传递给函数时除外）。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD Polynomial<Real> GreatestCommonDivisor(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    /// 系数f = factor[0]*factor[1]^2*factor[2]^3*...*factor[n-1]^n
    /// 根据无平方因式分解算法
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD std::vector<Polynomial<Real>> SquareFreeFactorization(const Polynomial<Real>& f);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    using PolynomialF = Polynomial<float>;
    using PolynomialD = Polynomial<double>;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_H
