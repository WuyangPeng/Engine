///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/13 17:56)

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
            : m_Begin{ begin },
              m_End{ end }
        {
        }

        Iterator begin() const noexcept
        {
            return m_Begin;
        }

        Iterator end() const noexcept
        {
            return m_End;
        }

    private:
        Iterator m_Begin;
        Iterator m_End;
    };

    template <typename Iterable,
              typename Iterator = decltype(std::begin(std::declval<Iterable>())),
              typename ReverseIterator = std::reverse_iterator<Iterator>>
    ReversalObject<ReverseIterator> Reverse(Iterable&& range)
    {
        return ReversalObject<ReverseIterator>(ReverseIterator(std::end(range)), ReverseIterator(std::begin(range)));
    }
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_RANGE_ITERATION_H