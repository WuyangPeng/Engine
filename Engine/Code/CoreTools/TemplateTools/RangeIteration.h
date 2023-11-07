///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/11/03 09:30)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H
#define CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H

#include <iterator>
#include <type_traits>

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
        return ReversalObject<ReverseIterator>(ReverseIterator(std::end(range)), ReverseIterator(std::begin(range)));
    }

    /// ���������˵���˷��������
    ///  std::vector<int> numbers = { a list of numbers };
    ///  for (const auto& element : gtl::reverse(numbers))
    ///  {
    ///      <do something with the element>;
    ///  }
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H