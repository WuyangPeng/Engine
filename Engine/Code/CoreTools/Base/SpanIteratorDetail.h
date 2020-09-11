//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/18 13:25)

#ifndef CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H
#define CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H

#include "SpanIterator.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <type_traits>

template <typename Iter>
CoreTools::SpanIterator<Iter>::SpanIterator(Iter begin, Iter end, Iter current) noexcept
    : m_Begin{ begin }, m_End{ end }, m_Current{ current }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Iter>
bool CoreTools::SpanIterator<Iter>::IsValid() const noexcept
{
    try
    {
        if (m_Begin <= m_Current && m_Current <= m_End)
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

    if (m_Begin <= m_Current && m_Current < m_End)
    {
        return *m_Current;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器无效。"s));
    }
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::operator->() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Current;
}

template <typename Iter>
CoreTools::SpanIterator<Iter>& CoreTools::SpanIterator<Iter>::operator++()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (m_End <= m_Current)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器增加时越界。"s));
    }

    ++m_Current;

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

    if (m_Current <= m_Begin)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器减少时越界。"s));
    }

    --m_Current;

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

    if (step > 0 && m_End - m_Current < step)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器增加时越界。"s));
    }

    if (step < 0 && m_Current - m_Begin < -step)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器减少时越界。"s));
    }

    m_Current += step;

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

    return m_Begin;
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::GetEnd() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_End;
}

template <typename Iter>
Iter CoreTools::SpanIterator<Iter>::GetCurrent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Current;
}

template <typename Iter>
typename CoreTools::SpanIterator<Iter>::DifferenceType CoreTools::SpanIterator<Iter>::GetRemainingCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_End - m_Current;
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
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器长度不足"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    return reinterpret_cast<const T&>(*m_Current);
#include STSTEM_WARNING_POP
}

template <typename Iter>
template <typename T>
T& CoreTools::SpanIterator<Iter>::ReinterpretCast()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<T&>(static_cast<const ClassType&>(*this).ReinterpretCast<T>());
#include STSTEM_WARNING_POP
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
typename Iter::difference_type CoreTools::operator-(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs)
{
    if (lhs.GetBegin() == rhs.GetBegin() && lhs.GetEnd() == rhs.GetEnd())
    {
        return lhs.GetCurrent() - rhs.GetCurrent();
    }
    {
        THROW_EXCEPTION(SYSTEM_TEXT("迭代器起始位置不相同。"s));
    }
}

template <typename Iter>
void CoreTools::IterSwap(const SpanIterator<Iter>& lhs, const SpanIterator<Iter>& rhs)
{
    iter_swap(lhs.GetCurrent(), rhs.GetCurrent());
}

#endif  // CORE_TOOLS_BASE_SPAN_ITERATOR_DETAIL_H
