// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 10:13)

#ifndef MATHEMATICS_ALGEBRA_POLYNOMIAL_H
#define MATHEMATICS_ALGEBRA_POLYNOMIAL_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "PolynomialDivideDetail.h"
#include "CoreTools/DataTypes/TupleDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polynomial : private boost::additive<Polynomial<Real>,
                                                                                    boost::additive<Polynomial<Real>, Real,
                                                                                                    boost::multiplicative<Polynomial<Real>, Real>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polynomial<Real>;
        using PolynomialDivide = PolynomialDivide<Real>;
        using Math = Math<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;

    public:
        explicit Polynomial(int degree = 0);
        Polynomial(const Polynomial& rhs);
        explicit Polynomial(const std::vector<Real>& tuple);
        Polynomial(int size, const Real* data);
        ~Polynomial();

        Polynomial& operator=(const Polynomial& rhs);

        Polynomial(Polynomial&& rhs) = default;
        Polynomial& operator=(Polynomial&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        // 成员访问

        // 重新设置会清空旧数据。
        void ResetDegree(int degree);

        int GetDegree() const noexcept;
        const Real* GetElements() const noexcept;
        Real* GetElements() noexcept;
        const Real& operator[](int index) const;
        Real& operator[](int index);
        Real GetEnd() const noexcept;

        // 计算多项式，p(t)。
        Real operator()(Real value) const noexcept;

        const Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator-=(Real scalar) noexcept;  // 输入是零阶的多项式
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        // 计算多项式的导数。
        const Polynomial GetDerivative() const;

        // 反转( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        const Polynomial GetInversion() const;

        // 通过消除所有的（接近）零的系数和使主导系数减少1阶。
        // 输入参数是阈值，用于指定一个系数实际上为零。
        void Compress(Real epsilon) noexcept;

        // 如果'this'为P（t）和除数（divisor）为D(t)使degree(P) >= degree(D)，
        // 则P(t) = Q(t) * D(t) + Real(t) 其中Q(t)是quotient
        // 使degree(Q) = degree(P) - degree(D)和Real(t)是remainder使
        // degree(Real) < degree(D)。 如果Q = 0 和 Real = P则返回
        // 值epsilon被用作剩余多项式系统的阈值。
        // 如果比epsilon小，则系数被假设为零。
        // 返回值第一个部分为quotient，第二部分为remainder。
        const PolynomialDivide Divide(const Polynomial& divisor, Real epsilon) const;

    private:
        void Swap(Polynomial& rhs) noexcept;

    private:
        int m_Degree;
        Real* m_Coeff;
    };

    template <typename Real>
    const Polynomial<Real> operator*(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs);

    template <typename T>
    bool Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs, const T epsilon);

    template <typename T>
    bool Approximate(const Polynomial<T>& lhs, const Polynomial<T>& rhs);

    using Polynomialf = Polynomial<float>;
    using Polynomiald = Polynomial<double>;
}
#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_ALGEBRA_POLYNOMIAL_H
