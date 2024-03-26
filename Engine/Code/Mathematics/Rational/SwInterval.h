/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Mathematics/Base/Math.h"

#include <array>
#include <limits>

/// SwInterval[e0,e1]必须满足e0 <= e1。
namespace Mathematics
{
    /// T必须是'float' 或 'double'。
    template <typename T>
    requires(std::is_floating_point_v<T>)
    class SwInterval
    {
    public:
        using ClassType = SwInterval<T>;

        using EndpointsType = std::array<T, 2>;

        /// 方便的常量。
        static constexpr T zero = Math<T>::GetValue(0);
        static constexpr T one = Math<T>::GetValue(1);
        static constexpr auto max = std::numeric_limits<T>::max();
        static constexpr auto inf = std::numeric_limits<T>::infinity();

    public:
        /// 构造函数这是创建间隔的唯一方法。
        /// 一旦创建，所有这些间隔都是不可变的。
        /// 构造函数SwInterval(T) 用于创建退化区间[e,e]。
        SwInterval() noexcept;
        explicit SwInterval(T e) noexcept;
        SwInterval(T e0, T e1);
        explicit SwInterval(EndpointsType endpoint);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。只能读取端点。
        /// 不能在算术运算之外修改端点。
        NODISCARD T operator[](int index) const;
        NODISCARD EndpointsType GetEndpoints() const noexcept;

        /// 用于计算表达式树的叶节点处的间隔的算术运算。
        /// 这些节点对应于表达式的原始浮点变量。
        /// 在类定义之后定义的非类运算符用于计算表达式树内部节点处的间隔。
        NODISCARD static SwInterval Add(T u, T v);
        NODISCARD static SwInterval Sub(T u, T v);
        NODISCARD static SwInterval Mul(T u, T v);
        NODISCARD static SwInterval Div(T u, T v);

        /// 仅供内部使用。这些由类定义之后定义的非类运算符使用。
        NODISCARD static SwInterval Add(T u0, T u1, T v0, T v1);
        NODISCARD static SwInterval Sub(T u0, T u1, T v0, T v1);
        NODISCARD static SwInterval Mul(T u0, T u1, T v0, T v1);
        NODISCARD static SwInterval Mul2(T u0, T u1, T v0, T v1);
        NODISCARD static SwInterval Div(T u0, T u1, T v0, T v1);
        NODISCARD static SwInterval Reciprocal(T v0, T v1);
        NODISCARD static SwInterval ReciprocalDown(T v);
        NODISCARD static SwInterval ReciprocalUp(T v);
        NODISCARD static SwInterval Reals();

        /// 一元运算。
        /// [e0,e1]的负值产生[-e1,-e0]。
        /// 在否定算术表达式中的“数字”的意义上，需要支持此运算。
        NODISCARD SwInterval operator+() const noexcept;
        NODISCARD SwInterval operator-() const;

        SwInterval& operator+=(T rhs);
        SwInterval& operator+=(const SwInterval& rhs);

        SwInterval& operator-=(T rhs);
        SwInterval& operator-=(const SwInterval& rhs);

        SwInterval& operator*=(T rhs);
        SwInterval& operator*=(const SwInterval& rhs);

        SwInterval& operator/=(T rhs);
        SwInterval& operator/=(const SwInterval& rhs);

    private:
        EndpointsType endpoints;
    };

    /// 加法运算。
    template <typename T>
    NODISCARD SwInterval<T> operator+(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator+(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator+(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>);

    /// 减法运算
    template <typename T>
    NODISCARD SwInterval<T> operator-(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator-(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator-(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>);

    /// 乘法运算。
    template <typename T>
    NODISCARD SwInterval<T> operator*(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator*(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator*(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>);

    /// 除法运算。
    /// 如果除数区间是[v0,v1]，且v0 < 0 < v1，
    /// 则返回的区间是(-infinity,+infinity)，
    /// 而不是并集((-infinity,1/v0),(1/v1,+infinity))。
    /// 应用程序应该通过基于[v0,0]和[0,v1]进行分支来避免这种情况。
    template <typename T>
    NODISCARD SwInterval<T> operator/(const SwInterval<T>& lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator/(T lhs, const SwInterval<T>& rhs) requires(std::is_floating_point_v<T>);

    template <typename T>
    NODISCARD SwInterval<T> operator/(const SwInterval<T>& lhs, T rhs) requires(std::is_floating_point_v<T>);

}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_SW_INTERVAL_H
