/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:30)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Integer.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Mathematics
{
    // N是每个整数分子/分母的32位字的数目
    template <int N>
    class SignRational final : private boost::arithmetic<SignRational<N>, boost::totally_ordered<SignRational<N>, boost::arithmetic<SignRational<N>, Integer<N>>>>
    {
    public:
        using ClassType = SignRational<N>;

        using IntegerType = Integer<N>;

    public:
        // 默认有理数是0/1
        SignRational() noexcept;

        explicit SignRational(const IntegerType& numerator) noexcept;
        SignRational(const IntegerType& numerator, const IntegerType& denominator);

        // 构造转换。
        template <typename T>
        explicit SignRational(T numerator);

        template <typename T>
        SignRational(T numerator, T denominator);

        CLASS_INVARIANT_DECLARE;

        // 成员访问
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

        // 计算有理数的绝对值。
        NODISCARD SignRational Abs() const;

        NODISCARD NumericalValueSymbol GetSign() const noexcept;

    private:
        // 抵消分子和分母的任何2的乘幂。
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

    // 比较。
    template <int N>
    NODISCARD bool operator==(const SignRational<N>& lhs, const SignRational<N>& rhs);
    template <int N>
    NODISCARD bool operator<(const SignRational<N>& lhs, const SignRational<N>& rhs);

    template <int N>
    std::ostream& operator<<(std::ostream& os, const SignRational<N>& rational);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_H
