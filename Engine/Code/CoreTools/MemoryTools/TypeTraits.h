/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:46)

#ifndef CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
#define CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    /// float, double或long double的IsArbitraryPrecision<T>::value是'false'。
    /// 对于自定义类型，需要特化为'true'。
    template <typename T>
    struct IsArbitraryPrecisionInternal : std::false_type
    {
    };

    template <typename T>
    struct IsArbitraryPrecision : IsArbitraryPrecisionInternal<T>::type
    {
    };

    /// float, double或long double的HasDivisionOperator<T>::value是'true'。
    template <typename T>
    struct HasDivisionOperatorInternal : std::false_type
    {
    };

    template <typename T>
    struct HasDivisionOperator : HasDivisionOperatorInternal<std::remove_cv_t<T>>::type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<float> : std::true_type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<double> : std::true_type
    {
    };

    template <>
    struct HasDivisionOperatorInternal<long double> : std::true_type
    {
    };

    /// 模板参数为“Parameters，bool Condition”的类中基于模板的条件编译(SFINAE)的模板别名。
    /// 示例用法为
    /// template <Parameters, bool Condition = DefaultCondition, TraitSelector<Condition> = 0>
    /// ReturnType MemberFunction(inputs)
    /// { implementation for Condition = true; }
    ///
    /// template <Parameters, bool Condition = DefaultCondition, TraitSelector<!Condition> = 0>
    /// ReturnType MemberFunction(inputs)
    /// { implementation for Condition = false; }
    template <bool Condition>
    using TraitSelector = std::enable_if_t<Condition, int>;

    /// 用于具有数字模板参数的类中基于模板的条件编译(SFINAE)的模板别名。选择的依据是数字类型是浮点还是任意精度。
    /// 示例用法为
    /// template <typename Numeric, IsNotArbitraryPrecisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { floating-point computations }
    ///
    /// template <typename Numeric, IsArbitraryPrecisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { arbitrary-precision computations }
    template <typename T>
    using IsNotArbitraryPrecisionType = std::enable_if_t<!IsArbitraryPrecision<T>::value, int>;

    template <typename T>
    using IsArbitraryPrecisionType = std::enable_if_t<IsArbitraryPrecision<T>::value, int>;

    /// 用于具有数字模板参数的类中基于模板的条件编译(SFINAE)的模板别名。选择的依据是数字类型是否支持除法。
    /// 示例用法为
    /// template <typename Numeric, IsDivisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { Numeric computations that use divisions }
    ///
    /// template <typename Numeric, IsNotDivisionType<Numeric> = 0>
    /// Numeric MemberFunction(Numeric inputs)
    /// { Numeric computations without divisions }
    template <typename T>
    using IsDivisionType = std::enable_if_t<HasDivisionOperator<T>::value, int>;

    template <typename T>
    using IsNotDivisionType = std::enable_if_t<!HasDivisionOperator<T>::value, int>;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
