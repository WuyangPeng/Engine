/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H
#define CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H

#include <iterator>
#include <type_traits>

/// 支持使用auto关键字在基于范围的for循环中进行反向迭代。例如
///  std::vector<int> numbers(4);
///   int i = 0;
///   for (auto& number : numbers)
///   {
///       number = i++;
///       std::cout << number << ' ';
///   }
///   // Output:  0 1 2 3
///
///   for (const auto& number : gte::reverse(numbers))
///   {
///       std::cout << number << ' ';
///   }
///   // Output:  3 2 1 0

namespace CoreTools
{
    template <typename Iterator>
    class ReversalObject final
    {
    public:
        ReversalObject(Iterator begin, Iterator end) noexcept
            : beginIterator{ begin },
              endIterator{ end }
        {
        }

        NODISCARD Iterator begin() const noexcept
        {
            return beginIterator;
        }

        NODISCARD Iterator end() const noexcept
        {
            return endIterator;
        }

    private:
        Iterator beginIterator;
        Iterator endIterator;
    };

    template <typename Iterable,
              typename Iterator = decltype(std::begin(std::declval<Iterable>())),
              typename ReverseIterator = std::reverse_iterator<Iterator>>
    NODISCARD ReversalObject<ReverseIterator> Reverse(Iterable&& range) noexcept
    {
        return ReversalObject<ReverseIterator>{ ReverseIterator(std::end(range)), ReverseIterator(std::begin(range)) };
    }

}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H