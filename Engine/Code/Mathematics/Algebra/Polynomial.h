///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 17:12)

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
    requires std::is_arithmetic_v<Real>
    class Polynomial final : private boost::additive<Polynomial<Real>, boost::additive<Polynomial<Real>, Real, boost::multiplicative<Polynomial<Real>, Real>>>
    {
    public:
        using ClassType = Polynomial<Real>;
        using PolynomialDivide = PolynomialDivide<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;

    public:
        explicit Polynomial(int degree);
        explicit Polynomial(const ContainerType& coeff);
        explicit Polynomial(ContainerType&& coeff);

        CLASS_INVARIANT_DECLARE;

        // 成员访问

        // 重新设置会清空旧数据。
        void ResetDegree(int degree);

        NODISCARD int GetDegree() const;
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetBegin() const noexcept;
        NODISCARD Real GetEnd() const noexcept;

        // 计算多项式，p(t)。
        NODISCARD Real operator()(Real value) const;

        NODISCARD ContainerType GetValue() const;
        void SetValue(const ContainerType& aCoeff);
        void SetValue(ContainerType&& aCoeff);

        NODISCARD Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator-=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        // 计算多项式的导数。
        NODISCARD Polynomial GetDerivative() const;

        // 反转( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        NODISCARD Polynomial GetInversion() const;

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
        NODISCARD PolynomialDivide Divide(const Polynomial& divisor, Real epsilon) const;

        NODISCARD Polynomial GetTranslation(Real t0) const;
        void EliminateLeadingZeros(Real epsilon);

    private:
        NODISCARD int GetCompressDegree(Real epsilon) const;

    private:
        ContainerType coeff;
    };

    template <typename Real>
    NODISCARD Polynomial<Real> operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename Real>
    NODISCARD Polynomial<Real> GreatestCommonDivisor(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    template <typename T>
    NODISCARD bool Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, T epsilon = Math<T>::GetZeroTolerance());

    template <typename Real>
    std::vector<Polynomial<Real>> SquareFreeFactorization(const Polynomial<Real>& f);

    using PolynomialF = Polynomial<float>;
    using PolynomialD = Polynomial<double>;
}

#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_H
