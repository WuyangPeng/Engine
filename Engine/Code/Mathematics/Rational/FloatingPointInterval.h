/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"

#include <array>

/// FloatingPointInterval[e0,e1]必须满足e0 <= e1。
namespace Mathematics
{
    /// FloatingPointType必须是'float' 或 'double'。
    template <typename FloatingPointType>
    requires(std::is_floating_point_v<FloatingPointType>)
    class FloatingPointInterval
    {
    public:
        using ClassType = FloatingPointInterval<FloatingPointType>;

        using EndpointsType = std::array<FloatingPointType, 2>;

    public:
        /// 构造函数这是创建间隔的唯一方法。
        /// 一旦创建，所有这些间隔都是不可变的。
        /// 构造函数FloatingPointInterval(FloatingPointType) 用于创建退化区间[e,e]。
        FloatingPointInterval() noexcept;
        explicit FloatingPointInterval(const FloatingPointType& e) noexcept;
        FloatingPointInterval(const FloatingPointType& e0, const FloatingPointType& e1);
        explicit FloatingPointInterval(EndpointsType endpoint);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。只能读取端点。
        /// 不能在算术运算之外修改端点。
        NODISCARD FloatingPointType operator[](int index) const;
        NODISCARD EndpointsType GetEndpoints() const noexcept;

        /// 用于计算表达式树的叶节点处的间隔的算术运算。
        /// 这些节点对应于表达式的原始浮点变量。
        /// 在类定义之后定义的非类运算符用于计算表达式树内部节点处的间隔。
        NODISCARD static FloatingPointInterval Add(const FloatingPointType& u, const FloatingPointType& v);
        NODISCARD static FloatingPointInterval Sub(const FloatingPointType& u, const FloatingPointType& v);
        NODISCARD static FloatingPointInterval Mul(const FloatingPointType& u, const FloatingPointType& v);
        NODISCARD static FloatingPointInterval Div(const FloatingPointType& u, const FloatingPointType& v);

        /// 调用此函数是为了计算两个区间乘积的下界。
        /// 在调用该函数之前，您需要调用std::fesetround(FE_DOWNWARD)。
        /// 其思想是在批处理模式下计算下限（多次调用ProductLowerBound），
        /// 以最大限度地减少FPU控制字状态的变化。
        NODISCARD static FloatingPointType ProductLowerBound(const EndpointsType& u, const EndpointsType& v);

        /// 调用此函数是为了计算两个区间乘积的上界。
        /// 在调用该函数之前，您需要调用std::fesetround(FE_UPWARD)。
        /// 其思想是在批处理模式（多次调用ProductUpperBound）中计算下限，
        /// 以最大限度地减少FPU控制字状态的变化。
        NODISCARD static FloatingPointType ProductUpperBound(const EndpointsType& u, const EndpointsType& v);

        /// 仅供内部使用。这些由类定义之后定义的非类运算符使用。
        NODISCARD static FloatingPointInterval Add(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval Sub(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval Mul(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval Mul2(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval Div(const FloatingPointType& u0, const FloatingPointType& u1, const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval Reciprocal(const FloatingPointType& v0, const FloatingPointType& v1);
        NODISCARD static FloatingPointInterval ReciprocalDown(const FloatingPointType& v);
        NODISCARD static FloatingPointInterval ReciprocalUp(const FloatingPointType& v);
        NODISCARD static FloatingPointInterval Reals();

        /// 一元运算。
        /// [e0,e1]的负值产生[-e1,-e0]。
        /// 在否定算术表达式中的“数字”的意义上，需要支持此运算。
        NODISCARD FloatingPointInterval operator+() const noexcept;
        NODISCARD FloatingPointInterval operator-() const;

        FloatingPointInterval& operator+=(const FloatingPointType& rhs);
        FloatingPointInterval& operator+=(const FloatingPointInterval& rhs);

        FloatingPointInterval& operator-=(const FloatingPointType& rhs);
        FloatingPointInterval& operator-=(const FloatingPointInterval& rhs);

        FloatingPointInterval& operator*=(const FloatingPointType& rhs);
        FloatingPointInterval& operator*=(const FloatingPointInterval& rhs);

        FloatingPointInterval& operator/=(const FloatingPointType& rhs);
        FloatingPointInterval& operator/=(const FloatingPointInterval& rhs);

    private:
        EndpointsType endpoints;
    };

    /// 加法运算。
    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator+(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator+(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator+(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    /// 减法运算
    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator-(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator-(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator-(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    /// 乘法运算。
    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator*(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator*(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator*(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    /// 除法运算。
    /// 如果除数区间是[v0,v1]，且v0 < 0 < v1，
    /// 则返回的区间是(-infinity,+infinity)，
    /// 而不是并集((-infinity,1/v0),(1/v1,+infinity))。
    /// 应用程序应该通过基于[v0,0]和[0,v1]进行分支来避免这种情况。
    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator/(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator/(const FloatingPointType& lhs, const FloatingPointInterval<FloatingPointType>& rhs) requires(std::is_floating_point_v<FloatingPointType>);

    template <typename FloatingPointType>
    NODISCARD FloatingPointInterval<FloatingPointType> operator/(const FloatingPointInterval<FloatingPointType>& lhs, const FloatingPointType& rhs) requires(std::is_floating_point_v<FloatingPointType>);

}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_FLOATING_POINT_INTERVAL_H
