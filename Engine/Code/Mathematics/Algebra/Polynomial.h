/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 10:57)

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
        /// ��һ�����캯������ָ�������Ķ���ʽ����������ϵ������Ϊ�㣨��ȷ����ʼ������
        /// ����������ϵ��������ǽ�����������Ϊ����ֵ��
        /// �ڵڶ������캯���У����ǳ�ʼ������������1��
        /// �������е�����ʹϵ��[��]��Ϊ�㣨�������г�ʼ����ֵ��Ϊ�㣩��
        explicit Polynomial(int degree);
        explicit Polynomial(const ContainerType& coefficient);

        explicit Polynomial(ContainerType&& coefficient) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// ֧�ֲ��ֹ��죬����δ֪ʱʹ��Ĭ�Ϲ��캯����ϵ��δ��ʼ����
        void SetDegree(int degree);

        /// ������ϵ������Ϊָ��ֵ��
        void SetCoefficients(Real value);

        /// ��Ա����

        NODISCARD int GetDegree() const;

        NODISCARD ContainerType GetCoefficients() const;
        void SetCoefficients(const ContainerType& aCoefficient);
        void SetCoefficients(ContainerType&& aCoefficient);

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetBegin() const noexcept;
        NODISCARD Real GetEnd() const noexcept;

        /// �������ʽ��p(t)��
        /// �������ʽ��Ч�������������㡣
        NODISCARD Real operator()(Real value) const noexcept;

        /// һԪ���㡣
        NODISCARD Polynomial operator+() const;
        NODISCARD Polynomial operator-() const;

        /// ���Դ������㡣
        Polynomial& operator+=(const Polynomial& rhs);
        Polynomial& operator-=(const Polynomial& rhs);
        Polynomial& operator*=(const Polynomial& rhs);
        Polynomial& operator+=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator-=(Real scalar) noexcept;  // ��������׵Ķ���ʽ
        Polynomial& operator*=(Real scalar) noexcept;
        Polynomial& operator/=(Real scalar);

        /// �������ʽ�ĵ�����
        NODISCARD Polynomial GetDerivative() const;

        /// ��ת( inv_poly[i] = poly[degree-i] for 0 <= i <= degree ).
        NODISCARD Polynomial GetInversion() const;

        /// ת��.  ��� 'this' �� p(t}, ���� p(t-t0).
        NODISCARD Polynomial GetTranslation(Real t0) const;

        /// ��������ʽ�е��κ�ǰ���㣬���ǽ���Ϊ0��ϵ��Ϊ0��
        /// ���������㵼�½���ĳ̶Ƚ���ʱ�������Ǳ�Ҫ�ġ�
        /// ���磬(1 + x + x^2) + (1 + 2*x - x^2) = (2 + 3*x)��
        /// ���������붼���н���2����˽�����Խ���2�����ġ�
        /// ��Ӻ����Ƿ��ֽ���ʵ������1��������ϵ������Ĵ�С��
        /// �˺���������������ڲ����ã�
        /// �����ڹ����ӿ��й������Է��������Լ���Ŀ����Ҫ����
        void EliminateLeadingZeros(Real epsilon);

        /// ͨ���������еģ��ӽ������ϵ����ʹ����ϵ������1�ס�
        /// �����������ֵ������ָ��һ��ϵ��ʵ����Ϊ�㡣
        void MakeCompress(Real epsilon);

        /// ���'this'ΪP(t)�ͳ���(divisor)ΪD(t)��ʹdegree(P) >= degree(D)��
        /// ��P(t) = Q(t) * D(t) + R(t) ����Q(t)��quotient
        /// ʹdegree(Q) = degree(P) - degree(D)��R(t)��remainderʹ
        /// degree(R) < degree(D)�� ���Q = 0 �� R = P�򷵻ء�
        /// ֵepsilon������ʣ�����ʽϵͳ����ֵ��
        /// �����epsilonС����ϵ��������Ϊ�㡣
        /// ����ֵ��һ������Ϊquotient���ڶ�����Ϊremainder��
        NODISCARD PolynomialDivide Divide(const Polynomial& divisor, Real epsilon) const;

        NODISCARD bool Equal(const Polynomial& rhs) const;
        NODISCARD bool Less(const Polynomial& rhs) const;

    private:
        NODISCARD int GetCompressDegree(Real epsilon) const;

    private:
        /// ��������ʹcoefficient.size() >= 1��
        ContainerType coefficient;
    };

    /// �Ƚϡ�
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

    /// ������������ʽ�����Լ����
    /// ���صĶ���ʽ����ǰ��ϵ��1����ֵ����ʽ���ݸ�����ʱ���⣩��
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD Polynomial<Real> GreatestCommonDivisor(const Polynomial<Real>& lhs, const Polynomial<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    /// ϵ��f = factor[0]*factor[1]^2*factor[2]^3*...*factor[n-1]^n
    /// ������ƽ����ʽ�ֽ��㷨
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
