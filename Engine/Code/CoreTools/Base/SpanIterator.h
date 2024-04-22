/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 16:37)

#ifndef CORE_TOOLS_BASE_SPAN_ITERATOR_H
#define CORE_TOOLS_BASE_SPAN_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include <array>
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
        using ConstPointerType = const typename Iter::value_type*;
        using ConstReferenceType = const typename Iter::value_type&;

    public:
        SpanIterator(Iter begin, Iter end) noexcept;
        SpanIterator(Iter begin, Iter end, Iter current) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstPointerType GetData() const;

        NODISCARD ConstReferenceType operator*() const;
        NODISCARD Iter operator->() const noexcept;

        SpanIterator<Iter>& operator++();
        NODISCARD SpanIterator<Iter> operator++(int);

        SpanIterator<Iter>& operator--();
        NODISCARD SpanIterator<Iter> operator--(int);

        SpanIterator<Iter>& operator+=(int step);
        SpanIterator<Iter>& operator-=(int step);

        NODISCARD Iter GetBegin() const noexcept;
        NODISCARD Iter GetEnd() const noexcept;
        NODISCARD Iter GetCurrent() const noexcept;
        NODISCARD Iter Get(int step) const;

        NODISCARD DifferenceType GetRemainingCount() const noexcept;

        /// Increase函数修改current。
        template <typename T>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        NODISCARD T Increase();

        template <typename T>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        void Increase(T value);

        template <typename T, int Size>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        NODISCARD std::array<T, Size> Increase();

        template <typename T, int Size>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        void Increase(const std::array<T, Size>& value);

        /// GetValue和SetValue函数不修改current。
        template <typename T>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        NODISCARD T GetValue(int step) const;

        template <typename T, int Size>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        NODISCARD std::array<T, Size> GetValue(int step) const;

        template <typename T>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        void SetValue(int step, T value);

        template <typename T, int Size>
        requires(sizeof(typename Iter::value_type) <= sizeof(T) && sizeof(T) % sizeof(typename Iter::value_type) == 0)
        void SetValue(int step, const std::array<T, Size>& value);

    private:
        template <typename T>
        NODISCARD const T& ReinterpretCast() const requires(std::is_arithmetic_v<ValueType> && std::is_arithmetic_v<T>);

        template <typename T>
        NODISCARD T& ReinterpretCast() requires(std::is_arithmetic_v<ValueType> && std::is_arithmetic_v<T>);

        template <typename T>
        NODISCARD const T& ReinterpretCast(int step) const requires(std::is_arithmetic_v<ValueType> && std::is_arithmetic_v<T>);

        template <typename T>
        NODISCARD T& ReinterpretCast(int step) requires(std::is_arithmetic_v<ValueType> && std::is_arithmetic_v<T>);

    private:
        Iter begin{};
        Iter end{};
        Iter current{};
    };

    template <typename Iter>
    NODISCARD typename Iter::difference_type operator-(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);

    /// 交换两个迭代器的值。
    template <typename Iter>
    void IterSwap(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs);
}

#endif  // CORE_TOOLS_BASE_SPAN_ITERATOR_H
