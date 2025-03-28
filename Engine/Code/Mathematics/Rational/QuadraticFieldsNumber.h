///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.7 (2024/03/04 10:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_H
#define MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_H

#include "Mathematics/MathematicsDll.h"

#include <array>

/// 类QuadraticFieldsNumber是具有N>=1平方根项的二次域的实现。
namespace Mathematics
{
    /// N >= 2平方根项的二次域的算术。
    /// d项是有理的，x系数是具有 N-1 >= 1 个平方根项的二次域中的元素。
    template <typename Real, int N>
    requires(0 < N)
    class QuadraticFieldsNumber
    {
    public:
        using ClassType = QuadraticFieldsNumber<Real, N>;

        using QuadraticFieldsNumberMinus1 = QuadraticFieldsNumber<Real, N - 1>;
        using Container = std::array<QuadraticFieldsNumberMinus1, 2>;

    public:
        /// 创建z = 0 + 0 * sqrt(0)，
        /// 其中0个系数是N-1个d项都设置为0，
        /// x个系数都设置为零的二次域元素。
        QuadraticFieldsNumber() noexcept;

        /// 创建z = 0 + 0 * sqrt(d)，
        /// 其中0个系数是N-1个d项都设置为0，
        /// x个系数都设置为零的二次域元素。
        explicit QuadraticFieldsNumber(Real d) noexcept;

        /// 创建z = x0 + x1 * sqrt(d)，其中x系数是具有N-1个d项的二次域元素。
        QuadraticFieldsNumber(const QuadraticFieldsNumberMinus1& x0, QuadraticFieldsNumberMinus1& x1, Real d) noexcept;

        /// 创建z = inX[0] + inX[1] * sqrt(inD)，其中x系数是具有N-1个d项的二次域元素。
        QuadraticFieldsNumber(const Container& x, Real d) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Container GetX() const noexcept;
        void SetX(const Container& aX) noexcept;

        NODISCARD Real GetD() const noexcept;
        void SetD(Real aD) noexcept;

        NODISCARD QuadraticFieldsNumberMinus1 GetX(int index) const;
        void SetX(int index, const QuadraticFieldsNumberMinus1& aX);

        NODISCARD const QuadraticFieldsNumberMinus1& operator[](int index) const;
        NODISCARD QuadraticFieldsNumberMinus1& operator[](int index);

    private:
        /// 二次域数是 x[0] + x[1] * sqrt(d)。
        Container x;
        Real d;
    };

    /// 一个平方根项的二次域的算术。
    template <typename Real>
    class QuadraticFieldsNumber<Real, 1>
    {
    public:
        using ClassType = QuadraticFieldsNumber<Real, 1>;

        using Container = std::array<Real, 2>;

    public:
        QuadraticFieldsNumber() noexcept;

        /// 创建 z = 0 + 0 * sqrt(d) = 0.。
        explicit QuadraticFieldsNumber(Real d) noexcept;

        /// 创建z = x0 + x1 * sqrt(d)。
        QuadraticFieldsNumber(Real x0, Real x1, Real d) noexcept;

        /// 创建z = inX[0] + inX[1] * sqrt(d)。
        QuadraticFieldsNumber(const Container& x, Real d) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Container GetX() const noexcept;
        void SetX(const Container& aX) noexcept;

        NODISCARD Real GetD() const noexcept;
        void SetD(Real aD) noexcept;

        NODISCARD Real GetX(int index) const;
        void SetX(int index, Real aX);

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

    private:
        /// 二次域数为 x[0] + x[1] * sqrt(d).
        Container x;
        Real d;
    };

    /// 一元运算。
    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator+(const QuadraticFieldsNumber<Real, N>& self);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator-(const QuadraticFieldsNumber<Real, N>& self);

    template <typename Real, int N>
    requires(0 < N)
    void Check(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    /// 只有当d值相同时，才能在二次域的元素之间进行算术更新。
    /// 要捕获不匹配，定义MATHEMATICS_USE_ASSERT_ON_QUADRATIC_FIELDS_NUMBER_MISMATCHED_D。
    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator+=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator+=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator-=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator-=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator*=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator*=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator/=(QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N>& operator/=(QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator+(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator+(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator+(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator-(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator-(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator-(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator*(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator*(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator*(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator/(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator/(const QuadraticFieldsNumber<Real, N>& lhs, Real rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator/(Real lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator==(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator!=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator<(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator<=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator>(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);

    template <typename Real, int N>
    requires(0 < N)
    NODISCARD QuadraticFieldsNumber<Real, N> operator>=(const QuadraticFieldsNumber<Real, N>& lhs, const QuadraticFieldsNumber<Real, N>& rhs);
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_QUADRATIC_FIELDS_NUMBER_H
