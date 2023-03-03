///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 15:4)

#ifndef CORE_TOOLS_BASE_SPAN_ITERATOR_H
#define CORE_TOOLS_BASE_SPAN_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Iter>
    class SpanIterator final
    {
    public:
        using ClassType = SpanIterator<Iter>;

        using ValueType = typename Iter::value_type;
        using DifferenceType = typename Iter::difference_type;
        using ConstPointerType = typename const Iter::value_type*;
        using ConstReferenceType = typename const Iter::value_type&;

    public:
        SpanIterator(Iter begin, Iter end) noexcept;
        SpanIterator(Iter begin, Iter end, Iter current) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstReferenceType operator*() const;
        NODISCARD Iter operator->() const noexcept;

        SpanIterator<Iter>& operator++();
        NODISCARD SpanIterator<Iter> operator++(int);

        SpanIterator<Iter>& operator--();
        NODISCARD SpanIterator<Iter> operator--(int);

        SpanIterator<Iter>& operator+=(const int step);
        SpanIterator<Iter>& operator-=(const int step);

        NODISCARD Iter GetBegin() const noexcept;
        NODISCARD Iter GetEnd() const noexcept;
        NODISCARD Iter GetCurrent() const noexcept;

        NODISCARD DifferenceType GetRemainingCount() const noexcept;

        template <typename T>
        NODISCARD T Increase();

        template <typename T>
        void Increase(T value);

    private:
        template <typename T>
        NODISCARD const T& ReinterpretCast() const;

        template <typename T>
        NODISCARD T& ReinterpretCast();

    private:
        Iter begin{};
        Iter end{};
        Iter current{};
    };

    template <typename Iter>
    NODISCARD typename Iter::difference_type operator-(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);

    // 交互两个迭代器的值。
    template <typename Iter>
    void IterSwap(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);
}

#endif  // CORE_TOOLS_BASE_SPAN_ITERATOR_H
