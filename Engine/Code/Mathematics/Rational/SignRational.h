///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/19 10:50)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Mathematics
{
    // N��ÿ����������/��ĸ��32λ�ֵ���Ŀ
    template <int N>
    class SignRational final : private boost::arithmetic<SignRational<N>, boost::totally_ordered<SignRational<N>, boost::arithmetic<SignRational<N>, Integer<N>>>>
    {
    public:
        using ClassType = SignRational<N>;
        using Integer = Integer<N>;

    public:
        // Ĭ����������0/1
        SignRational();

        explicit SignRational(const Integer& numerator);
        SignRational(const Integer& numerator, const Integer& denominator);

        // ����ת����
        template <typename T>
        explicit SignRational(T numerator);

        template <typename T>
        SignRational(T numerator, T denominator);

        CLASS_INVARIANT_DECLARE;

        //��Ա����
        [[nodiscard]] const Integer GetNumerator() const noexcept;
        [[nodiscard]] const Integer GetDenominator() const noexcept;
        void Set(const Integer& numerator, const Integer& denominator);

        [[nodiscard]] const SignRational operator-() const;
        SignRational& operator+=(const SignRational& rhs);
        SignRational& operator-=(const SignRational& rhs);
        SignRational& operator*=(const SignRational& rhs);
        SignRational& operator/=(const SignRational& rhs);

        SignRational& operator+=(const Integer& rhs);
        SignRational& operator-=(const Integer& rhs);
        SignRational& operator*=(const Integer& rhs);
        SignRational& operator/=(const Integer& rhs);

        template <typename T>
        [[nodiscard]] T ConvertTo() const;

        // �����������ľ���ֵ��
        [[nodiscard]] const SignRational Abs() const;

        [[nodiscard]] NumericalValueSymbol GetSign() const noexcept;

    private:
        // �������Ӻͷ�ĸ���κ�2�ĳ��ݡ�
        void EliminatePowersOfTwo();
        int GetPowers() const;

        template <typename T>
        void ConvertToRational(T value);

    private:
        Integer m_Numerator;
        Integer m_Denominator;
    };

    template <int N>
    [[nodiscard]] const SignRational<N> operator-(const Integer<N>& integer, const SignRational<N>& rational);

    template <int N>
    [[nodiscard]] const SignRational<N> operator/(const Integer<N>& integer, const SignRational<N>& rational);

    // �Ƚϡ�
    template <int N>
    [[nodiscard]] bool operator==(const SignRational<N>& lhs, const SignRational<N>& rhs);
    template <int N>
    [[nodiscard]] bool operator<(const SignRational<N>& lhs, const SignRational<N>& rhs);

    template <int N>
    std::ostream& operator<<(std::ostream& os, const SignRational<N>& rational);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_H
