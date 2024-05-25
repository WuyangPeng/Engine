/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/14 20:48)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_DETAIL_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_DETAIL_H

#include "ContainerAdapterTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Container, typename ElementType>
ElementType CoreTools::ContainerAdapterTesting::ComputeSum(const Container& container)
{
    using T = typename ElementType::value_type;

    ElementType average{ T{}, T{} };
    for (const auto& point : container)
    {
        for (auto i = 0u; i < point.size(); ++i)
        {
            average.at(i) += point.at(i);
        }
    }

    return average;
}

template <typename Container, typename ElementType>
ElementType CoreTools::ContainerAdapterTesting::ComputeAverage(const Container& container)
{
    using T = typename ElementType::value_type;

    auto average = ComputeSum(container);

    for (auto i = 0u; i < average.size(); ++i)
    {
        average.at(i) /= boost::numeric_cast<T>(container.size());
    }

    return average;
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_DETAIL_H