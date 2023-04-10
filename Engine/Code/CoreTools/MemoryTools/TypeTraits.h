///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/10 10:34)

#ifndef CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
#define CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{

    template <typename T>
    struct IsArbitraryPrecisionInternal : std::false_type
    {
    };

    template <typename T>
    struct IsArbitraryPrecision : IsArbitraryPrecisionInternal<T>::type
    {
    };

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

    template <bool Condition>
    using TraitSelector = std::enable_if_t<Condition, size_t>;

    template <typename T>
    using IsNotArbitraryPrecisionType = std::enable_if_t<!IsArbitraryPrecision<T>::value, size_t>;

    template <typename T>
    using IsArbitraryPrecisionType = std::enable_if_t<IsArbitraryPrecision<T>::value, size_t>;

    template <typename T>
    using IsDivisionType = std::enable_if_t<HasDivisionOperator<T>::value, size_t>;

    template <typename T>
    using IsNotDivisionType = std::enable_if_t<!HasDivisionOperator<T>::value, size_t>;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_TYPE_TRAITS_H
