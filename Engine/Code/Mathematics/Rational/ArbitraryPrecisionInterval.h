/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 13:38)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_H
#define MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/MemoryTools/TypeTraits.h"

#include <array>

namespace Mathematics
{
    /// 区间[e0,e1]必须满足e0 <= e1。
    /// APType必须是IsArbitraryPrecision类型。
    template <typename ArbitraryPrecisionType>
    requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value)
    class ArbitraryPrecisionInterval
    {
    public:
        using ClassType = ArbitraryPrecisionInterval<ArbitraryPrecisionType>;

        using EndpointsType = std::array<ArbitraryPrecisionType, 2>;

    public:
        /// 构造函数是创建间隔的唯一方法。
        /// 一旦创建，所有这些间隔都是不可变的。
        /// 构造函数ArbitraryPrecisionInterval(ArbitraryPrecisionType)用于创建退化区间[e,e]。
        NODISCARD static ArbitraryPrecisionInterval CreateZero() noexcept(noexcept(ArbitraryPrecisionType::CreateZero()));

        explicit ArbitraryPrecisionInterval(const ArbitraryPrecisionType& e) noexcept;
        ArbitraryPrecisionInterval(const ArbitraryPrecisionType& e0, const ArbitraryPrecisionType& e1);
        explicit ArbitraryPrecisionInterval(EndpointsType endpoint);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。只能读取端点。
        /// 不能在算术运算之外修改端点。
        NODISCARD ArbitraryPrecisionType operator[](int index) const;
        NODISCARD EndpointsType GetEndpoints() const noexcept;

        /// 用于计算表达式树的叶节点处的间隔的算术运算。
        /// 这些节点对应于表达式的原始浮点变量。
        /// 在类定义之后定义的非类运算符用于计算表达式树内部节点处的间隔。
        NODISCARD static ArbitraryPrecisionInterval Add(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v);
        NODISCARD static ArbitraryPrecisionInterval Sub(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v);
        NODISCARD static ArbitraryPrecisionInterval Mul(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v);
        NODISCARD static ArbitraryPrecisionInterval Div(const ArbitraryPrecisionType& u, const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);

        ///
        /// 仅供内部使用。这些由类定义之后定义的非类运算符使用。
        NODISCARD static ArbitraryPrecisionInterval Add(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1);
        NODISCARD static ArbitraryPrecisionInterval Sub(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1);
        NODISCARD static ArbitraryPrecisionInterval Mul(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1);
        NODISCARD static ArbitraryPrecisionInterval Mul2(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1);
        NODISCARD static ArbitraryPrecisionInterval Div(const ArbitraryPrecisionType& u0, const ArbitraryPrecisionType& u1, const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);
        NODISCARD static ArbitraryPrecisionInterval Reciprocal(const ArbitraryPrecisionType& v0, const ArbitraryPrecisionType& v1) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);
        NODISCARD static ArbitraryPrecisionInterval ReciprocalDown(const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);
        NODISCARD static ArbitraryPrecisionInterval ReciprocalUp(const ArbitraryPrecisionType& v) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);
        NODISCARD static ArbitraryPrecisionInterval Reals();

        /// 一元运算。
        /// [e0,e1]的负值产生[-e1,-e0]。
        /// 在否定算术表达式中的“数字”的意义上，需要支持此运算。
        NODISCARD ArbitraryPrecisionInterval operator+() const noexcept;
        NODISCARD ArbitraryPrecisionInterval operator-() const;

        ArbitraryPrecisionInterval& operator+=(const ArbitraryPrecisionType& rhs);
        ArbitraryPrecisionInterval& operator+=(const ArbitraryPrecisionInterval& rhs);

        ArbitraryPrecisionInterval& operator-=(const ArbitraryPrecisionType& rhs);
        ArbitraryPrecisionInterval& operator-=(const ArbitraryPrecisionInterval& rhs);

        ArbitraryPrecisionInterval& operator*=(const ArbitraryPrecisionType& rhs);
        ArbitraryPrecisionInterval& operator*=(const ArbitraryPrecisionInterval& rhs);

        ArbitraryPrecisionInterval& operator/=(const ArbitraryPrecisionType& rhs) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);
        ArbitraryPrecisionInterval& operator/=(const ArbitraryPrecisionInterval& rhs) requires(CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);

    private:
        explicit ArbitraryPrecisionInterval(CoreTools::DisableNotThrow disableNotThrow) noexcept(noexcept(ArbitraryPrecisionType::CreateZero()));

    private:
        EndpointsType endpoints;
    };

    /// 加法运算。
    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator+(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator+(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator+(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    /// 减法运算
    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator-(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator-(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator-(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    /// 乘法运算。
    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator*(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator*(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator*(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value);

    /// 除法运算。
    /// 如果除数区间是[v0,v1]，且v0 < 0 < v1，
    /// 则返回的区间是(-infinity,+infinity)，
    /// 而不是并集((-infinity,1/v0),(1/v1,+infinity))。
    /// 应用程序应该通过基于[v0,0]和[0,v1]进行分支来避免这种情况。
    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator/(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator/(const ArbitraryPrecisionType& lhs, const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);

    template <typename ArbitraryPrecisionType>
    NODISCARD ArbitraryPrecisionInterval<ArbitraryPrecisionType> operator/(const ArbitraryPrecisionInterval<ArbitraryPrecisionType>& lhs, const ArbitraryPrecisionType& rhs) requires(CoreTools::IsArbitraryPrecision<ArbitraryPrecisionType>::value && CoreTools::HasDivisionOperator<ArbitraryPrecisionType>::value);

}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_ARBITRARY_PRECISION_INTERVAL_H
