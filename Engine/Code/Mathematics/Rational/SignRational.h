/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:30)

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

        using IntegerType = Integer<N>;

    public:
        // Ĭ����������0/1
        SignRational() noexcept;

        explicit SignRational(const IntegerType& numerator) noexcept;
        SignRational(const IntegerType& numerator, const IntegerType& denominator);

        // ����ת����
        template <typename T>
        explicit SignRational(T numerator);

        template <typename T>
        SignRational(T numerator, T denominator);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����
        NODISCARD IntegerType GetNumerator() const noexcept;
        NODISCARD IntegerType GetDenominator() const noexcept;
        void Set(const IntegerType& newNumerator, const IntegerType& newDenominator);

        NODISCARD SignRational operator-() const;
        SignRational& operator+=(const SignRational& rhs);
        SignRational& operator-=(const SignRational& rhs);
        SignRational& operator*=(const SignRational& rhs);
        SignRational& operator/=(const SignRational& rhs);

        SignRational& operator+=(const IntegerType& rhs);
        SignRational& operator-=(const IntegerType& rhs);
        SignRational& operator*=(const IntegerType& rhs);
        SignRational& operator/=(const IntegerType& rhs);

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
        IntegerType numerator;
        IntegerType denominator;
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
