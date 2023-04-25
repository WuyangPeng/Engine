///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_DETAIL_H

#include "RawIterators.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

template <typename T>
CoreTools::RawConstIterator<T>::RawConstIterator(pointer pointer, int offset) noexcept
    : master{ pointer + offset }

#include STSTEM_WARNING_POP
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::RawConstIterator<T>::IsValid() const noexcept
{
    if (master != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
typename CoreTools::RawConstIterator<T>::reference CoreTools::RawConstIterator<T>::operator*() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return *master;
}

template <typename T>
typename CoreTools::RawConstIterator<T>::pointer CoreTools::RawConstIterator<T>::operator->() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return master;
}

template <typename T>
typename CoreTools::RawConstIterator<T>::reference CoreTools::RawConstIterator<T>::operator[](ptrdiff_t offset) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return master[offset];
}

template <typename T>
CoreTools::RawConstIterator<T>& CoreTools::RawConstIterator<T>::operator++() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ++master;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename T>
CoreTools::RawConstIterator<T> CoreTools::RawConstIterator<T>::operator++(int) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto current = *this;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ++master;

#include STSTEM_WARNING_POP

    return current;
}

template <typename T>
CoreTools::RawConstIterator<T>& CoreTools::RawConstIterator<T>::operator--() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    --master;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename T>
CoreTools::RawConstIterator<T> CoreTools::RawConstIterator<T>::operator--(int) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto current = *this;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    --master;

#include STSTEM_WARNING_POP

    return current;
}

template <typename T>
CoreTools::RawConstIterator<T>& CoreTools::RawConstIterator<T>::operator+=(ptrdiff_t offset) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    master += offset;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename T>
CoreTools::RawConstIterator<T> CoreTools::RawConstIterator<T>::operator+(ptrdiff_t offset) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto current = *this;

    return current += offset;
}

template <typename T>
CoreTools::RawConstIterator<T>& CoreTools::RawConstIterator<T>::operator-=(ptrdiff_t offset) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    master -= offset;

#include STSTEM_WARNING_POP

    return *this;
}

template <typename T>
CoreTools::RawConstIterator<T> CoreTools::RawConstIterator<T>::operator-(ptrdiff_t offset) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto current = *this;

    return current -= offset;
}

template <typename T>
ptrdiff_t CoreTools::RawConstIterator<T>::operator-(const RawConstIterator& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return master - rhs.master;
}

template <typename T>
bool CoreTools::RawConstIterator<T>::operator==(const RawConstIterator& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return master == rhs.master;
}

template <typename T>
bool CoreTools::RawConstIterator<T>::operator<(const RawConstIterator& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return master < rhs.master;
}

template <typename T>
CoreTools::RawIterator<T>::RawIterator(pointer pointer, int offset) noexcept
    : ParentType{ pointer, offset }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::RawIterator<T>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename T>
typename CoreTools::RawIterator<T>::reference CoreTools::RawIterator<T>::operator*() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<reference>(ParentType::operator*());

#include STSTEM_WARNING_POP
}

#include STSTEM_WARNING_POP

template <typename T>
typename CoreTools::RawIterator<T>::pointer CoreTools::RawIterator<T>::operator->()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return const_cast<pointer>(ParentType::operator->());
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator++() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::operator++();

    return *this;
}

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator++(int) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto current = *this;

    ParentType::operator++();

    return current;
}

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator--() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::operator--();

    return *this;
}

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator--(int) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto current = *this;

    ParentType::operator--();

    return current;
}

template <typename T>
CoreTools::RawIterator<T>& CoreTools::RawIterator<T>::operator+=(ptrdiff_t offset) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::operator+=(offset);

    return *this;
}

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator+(ptrdiff_t offset) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto current = *this;

    return current += offset;
}

template <typename T>
CoreTools::RawIterator<T>& CoreTools::RawIterator<T>::operator-=(ptrdiff_t offset) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::operator-=(offset);

    return *this;
}

template <typename T>
CoreTools::RawIterator<T> CoreTools::RawIterator<T>::operator-(ptrdiff_t offset) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto current = *this;

    return current -= offset;
}

#include STSTEM_WARNING_POP

#endif  // CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_DETAIL_H
