///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 17:12)

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

        // ��Ա����

        // �������û���վ����ݡ�
        void ResetDegree(int degree);

        NODISCARD int GetDegree() const;
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetBegin() const noexcept;
        NODISCARD Real GetEnd() const noexcept;

        // �������ʽ��p(t)��
        NODISCARD Real operator()(Real value) const;

        NODISCARD ContainerType GetValue() const;
        void SetValue(const ContainerType& aCoeff);
        void SetValue(ContainerType&& aCoeff);

        NODISCARD Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator-=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        // �������ʽ�ĵ�����
        NODISCARD Polynomial GetDerivative() const;

        // ��ת( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        NODISCARD Polynomial GetInversion() const;

        // ͨ���������еģ��ӽ������ϵ����ʹ����ϵ������1�ס�
        // �����������ֵ������ָ��һ��ϵ��ʵ����Ϊ�㡣
        void Compress(Real epsilon);

        // ���'this'ΪP��t���ͳ�����divisor��ΪD(t)ʹdegree(P) >= degree(D)��
        // ��P(t) = Q(t) * D(t) + Real(t) ����Q(t)��quotient
        // ʹdegree(Q) = degree(P) - degree(D)��Real(t)��remainderʹ
        // degree(Real) < degree(D)�� ���Q = 0 �� Real = P�򷵻�
        // ֵepsilon������ʣ�����ʽϵͳ����ֵ��
        // �����epsilonС����ϵ��������Ϊ�㡣
        // ����ֵ��һ������Ϊquotient���ڶ�����Ϊremainder��
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
