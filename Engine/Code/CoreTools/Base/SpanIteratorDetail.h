///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:46)

#ifndef CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H
#define CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H

#include "SpanIterator.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Iter>
CoreTools::SpanIterator<Iter>::SpanIterator(Iter begin, Iter end) noexcept
    : SpanIterator{ begin, end, begin }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>::SpanIterator(Iter begin, Iter end, Iter current) noexcept
    : begin{ std::move(begin) }, end{ std::move(end) }, current{ std::move(current) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Iter>
bool CoreTools::SpanIterator<Iter>::IsValid() const noexcept
{
    try
    {
        if (begin <= current && current <= end)
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Iter>
typename CoreTools::SpanIterator<Iter>::ConstReferenceType CoreTools::SpanIterator<Iter>::operator*() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (begin <= current && current < end)
    {
        return *current;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器无效。"s))
    }
}

template <typename Iter>
typename CoreTools::SpanIterator<Iter>::ConstPointerType CoreTools::SpanIterator<Iter>::GetData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return &(this->operator*());
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return current;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>& CoreTools::SpanIterator<Iter>::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (end <= current)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器增加时越界。"s))
    }

    ++current;

    return *this;
}

template <typename Iter>
CoreTools::SpanIterator<Iter> CoreTools::SpanIterator<Iter>::operator++(int)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto result = *this;
    ++*this;

    return result;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>& CoreTools::SpanIterator<Iter>::operator--()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (current <= begin)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器减少时越界。"s))
    }

    --current;

    return *this;
}

template <typename Iter>
CoreTools::SpanIterator<Iter> CoreTools::SpanIterator<Iter>::operator--(int)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto result = *this;
    --*this;

    return result;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>& CoreTools::SpanIterator<Iter>::operator+=(const int step)
{
    if (step == 0)
    {
        return *this;
    }

    if (step > 0 && end - current < step)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器增加时越界。"s))
    }

    if (step < 0 && current - begin < -step)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器减少时越界。"s))
    }

    current += step;

    return *this;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>& CoreTools::SpanIterator<Iter>::operator-=(const int step)
{
    *this += (-step);

    return *this;
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::GetBegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return begin;
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::GetEnd() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return end;
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::GetCurrent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return current;
}

template <typename Iter>
typename CoreTools::SpanIterator<Iter>::DifferenceType CoreTools::SpanIterator<Iter>::GetRemainingCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return end - current;
}

template <typename Iter>
template <typename T>
const T& CoreTools::SpanIterator<Iter>::ReinterpretCast() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType must be arithmetic.");
    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

    const auto remainingCount = GetRemainingCount();
    if (remainingCount * sizeof(ValueType) < sizeof(T))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器长度不足"s))
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const T&>(*current);

#include SYSTEM_WARNING_POP
}

template <typename Iter>
template <typename T>
T& CoreTools::SpanIterator<Iter>::ReinterpretCast()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T&>(static_cast<const ClassType&>(*this).ReinterpretCast<T>());

#include SYSTEM_WARNING_POP
}

template <typename Iter>
template <typename T>
const T& CoreTools::SpanIterator<Iter>::ReinterpretCast(int step) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    static_assert(std::is_arithmetic_v<ValueType>, "ValueType must be arithmetic.");
    static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

    const auto endStep = current + step * sizeof(ValueType);

    if (end <= endStep)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器长度不足"s))
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const T&>(*(endStep));

#include SYSTEM_WARNING_POP
}

template <typename Iter>
template <typename T>
T& CoreTools::SpanIterator<Iter>::ReinterpretCast(int step)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T&>(static_cast<const ClassType&>(*this).ReinterpretCast<T>(step));

#include SYSTEM_WARNING_POP
}

template <typename Iter>
template <typename T>
T CoreTools::SpanIterator<Iter>::Increase()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto result = ReinterpretCast<T>();

    *this += sizeof(T);

    return result;
}

template <typename Iter>
template <typename T>
void CoreTools::SpanIterator<Iter>::Increase(T value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& result = ReinterpretCast<T>();

    result = value;

    *this += sizeof(T);
}

template <typename Iter>
template <typename T>
T CoreTools::SpanIterator<Iter>::GetValue(int step) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ReinterpretCast<T>(step);
}

template <typename Iter>
template <typename T, int Size>
NODISCARD std::array<T, Size> CoreTools::SpanIterator<Iter>::GetValue(int step) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    constexpr auto proportion = sizeof(T) / sizeof(ValueType);

    const auto* endPosition = &ReinterpretCast<T>(step + Size * proportion);

    std::array<T, Size> result{};

    auto index = Size;
    for (auto& element : result)
    {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)

        element = *(endPosition - index);

#include SYSTEM_WARNING_POP

        --index;
    }

    return result;
}

template <typename Iter>
template <typename T>
void CoreTools::SpanIterator<Iter>::SetValue(int step, T value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto& result = ReinterpretCast<T>(step);

    result = value;
}

template <typename Iter>
template <typename T, int Size>
void CoreTools::SpanIterator<Iter>::SetValue(int step, const std::array<T, Size>& value)
{
    constexpr auto proportion = sizeof(T) / sizeof(ValueType);

    auto* endPosition = &ReinterpretCast<T>(step + Size * proportion);

    auto index = Size;
    for (const auto& element : value)
    {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)

        *(endPosition - index) = element;

#include SYSTEM_WARNING_POP

        --index;
    }
}

template <typename Iter>
typename Iter::difference_type CoreTools::operator-(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs)
{
    if (lhs.GetBegin() == rhs.GetBegin() && lhs.GetEnd() == rhs.GetEnd())
    {
        return lhs.GetCurrent() - rhs.GetCurrent();
    }
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器起始位置不相同。"s))
    }
}

template <typename Iter>
void CoreTools::IterSwap(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs)
{
    iter_swap(lhs.GetCurrent(), rhs.GetCurrent());
}

#endif  // CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H
