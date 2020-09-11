//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 13:25)

#ifndef CORE_TOOLS_BASE_SPAN_ITERATOR_H
#define CORE_TOOLS_BASE_SPAN_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Iter>
    class SpanIterator
    {
    public:
        using ClassType = SpanIterator<Iter>;

        using ValueType = typename Iter::value_type;
        using DifferenceType = typename Iter::difference_type;
        using ConstPointerType = typename const Iter::value_type*;
        using ConstReferenceType = typename const Iter::value_type&;

    public:
        SpanIterator(Iter begin, Iter end, Iter current) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConstReferenceType operator*() const;
        [[nodiscard]] Iter operator->() const noexcept;

        SpanIterator<Iter>& operator++();
        [[nodiscard]] SpanIterator<Iter> operator++(int);

        SpanIterator<Iter>& operator--();
        [[nodiscard]] SpanIterator<Iter> operator--(int);

        SpanIterator<Iter>& operator+=(const int step);
        SpanIterator<Iter>& operator-=(const int step);

        [[nodiscard]] Iter GetBegin() const noexcept;
        [[nodiscard]] Iter GetEnd() const noexcept;
        [[nodiscard]] Iter GetCurrent() const noexcept;

        [[nodiscard]] DifferenceType GetRemainingCount() const;        

        template <typename T>
        [[nodiscard]] T Increase();

        template <typename T>
        [[nodiscard]] void Increase(T value); 

    private: 
        template <typename T>
        [[nodiscard]] const T& ReinterpretCast() const;

        template <typename T>
        [[nodiscard]] T& ReinterpretCast();

    private:
        Iter m_Begin{};
        Iter m_End{};
        Iter m_Current{};
    };

    template <typename Iter>
    [[nodiscard]] typename Iter::difference_type operator-(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);

    template <typename Iter>
    void IterSwap(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);
}

#endif  // CORE_TOOLS_BASE_SPAN_ITERATOR_H
