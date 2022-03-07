///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/11 16:37)

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
        SignRational() noexcept;

        explicit SignRational(const Integer& numerator) noexcept;
        SignRational(const Integer& numerator, const Integer& denominator);

        // ����ת����
        template <typename T>
        explicit SignRational(T numerator);

        template <typename T>
        SignRational(T numerator, T denominator);

        CLASS_INVARIANT_DECLARE;

        //��Ա����
        NODISCARD Integer GetNumerator() const noexcept;
        NODISCARD Integer GetDenominator() const noexcept;
        void Set(const Integer& newNumerator, const Integer& newDenominator);

        NODISCARD SignRational operator-() const;
        SignRational& operator+=(const SignRational& rhs);
        SignRational& operator-=(const SignRational& rhs);
        SignRational& operator*=(const SignRational& rhs);
        SignRational& operator/=(const SignRational& rhs);

        SignRational& operator+=(const Integer& rhs);
        SignRational& operator-=(const Integer& rhs);
        SignRational& operator*=(const Integer& rhs);
        SignRational& operator/=(const Integer& rhs);

        template <typename T>
        NODISCARD T ConvertTo() const;

        // �����������ľ���ֵ��
        NODISCARD SignRational Abs() const;

        NODISCARD NumericalValueSymbol GetSign() const noexcept;

    private:
        // �������Ӻͷ�ĸ���κ�2�ĳ��ݡ�
        void EliminatePowersOfTwo();
        int GetPowers() const;

        template <typename T>
        void ConvertToRational(T value);

    private:
        Integer numerator;
        Integer denominator;
    };

    template <int N>
    NODISCARD SignRational<N> operator-(const Integer<N>& integer, const SignRational<N>& rational);

    template <int N>
    NODISCARD SignRational<N> operator/(const Integer<N>& integer, const SignRational<N>& rational);

    // �Ƚϡ�
    template <int N>
    NODISCARD bool operator==(const SignRational<N>& lhs, const SignRational<N>& rhs);
    template <int N>
    NODISCARD bool operator<(const SignRational<N>& lhs, const SignRational<N>& rhs);

    template <int N>
    std::ostream& operator<<(std::ostream& os, const SignRational<N>& rational);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_H
