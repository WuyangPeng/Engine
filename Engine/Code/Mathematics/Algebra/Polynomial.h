// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:13)

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

        // ��Ա����

        // �������û���վ����ݡ�
        void ResetDegree(int degree);

        int GetDegree() const noexcept;
        const Real* GetElements() const noexcept;
        Real* GetElements() noexcept;
        const Real& operator[](int index) const;
        Real& operator[](int index);
        Real GetEnd() const noexcept;

        // �������ʽ��p(t)��
        Real operator()(Real value) const noexcept;

        const Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator-=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        // �������ʽ�ĵ�����
        const Polynomial GetDerivative() const;

        // ��ת( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        const Polynomial GetInversion() const;

        // ͨ���������еģ��ӽ������ϵ����ʹ����ϵ������1�ס�
        // �����������ֵ������ָ��һ��ϵ��ʵ����Ϊ�㡣
        void Compress(Real epsilon) noexcept;

        // ���'this'ΪP��t���ͳ�����divisor��ΪD(t)ʹdegree(P) >= degree(D)��
        // ��P(t) = Q(t) * D(t) + Real(t) ����Q(t)��quotient
        // ʹdegree(Q) = degree(P) - degree(D)��Real(t)��remainderʹ
        // degree(Real) < degree(D)�� ���Q = 0 �� Real = P�򷵻�
        // ֵepsilon������ʣ�����ʽϵͳ����ֵ��
        // �����epsilonС����ϵ��������Ϊ�㡣
        // ����ֵ��һ������Ϊquotient���ڶ�����Ϊremainder��
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
