///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/10 10:08)

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

        // ��Ա����

        // �������û���վ����ݡ�
        void ResetDegree(int degree);

        [[nodiscard]] int GetDegree() const;
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);
        [[nodiscard]] Real GetBegin() const noexcept;
        [[nodiscard]] Real GetEnd() const noexcept;

        // �������ʽ��p(t)��
        [[nodiscard]] Real operator()(Real value) const;

        [[nodiscard]] ContainerType GetValue() const;
        void SetValue(const ContainerType& coeff);

        [[nodiscard]] const Polynomial operator-() const;

        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar);  // ��������׵Ķ���ʽ
        Polynomial& operator-=(Real scalar);  // ��������׵Ķ���ʽ
        Polynomial& operator*=(Real scalar);
        Polynomial& operator/=(Real scalar);

        // �������ʽ�ĵ�����
        [[nodiscard]] const Polynomial GetDerivative() const;

        // ��ת( invpoly[i] = poly[degree-i] for 0 <= i <= degree ).
        [[nodiscard]] const Polynomial GetInversion() const;

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
