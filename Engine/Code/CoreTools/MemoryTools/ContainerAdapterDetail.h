///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:36)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_DETAIL_H

#include "ContainerAdapter.h"
#include "RawIteratorsDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, int N>
requires(N > 0) CoreTools::ContainerAdapter<T, N>::ContainerAdapter(T* elements, int numElements)
    : elements{ elements }
{
    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"))
    }

    System::UnusedFunction(numElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T, int N>
requires(N > 0)
CoreTools::ContainerAdapter<T, N>::ContainerAdapter(ContainerAdapter&& rhs) noexcept
    : elements{ rhs.elements }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename T, int N>
requires(N > 0)
CoreTools::ContainerAdapter<T, N>& CoreTools::ContainerAdapter<T, N>::operator=(ContainerAdapter&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    elements = rhs.elements;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, int N>
requires(N > 0) bool CoreTools::ContainerAdapter<T, N>::IsValid() const noexcept
{
    return elements != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, int N>
requires(N > 0) T* CoreTools::ContainerAdapter<T, N>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, int N>
requires(N > 0) const T* CoreTools::ContainerAdapter<T, N>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return elements;
}

template <typename T, int N>
requires(N > 0) const T& CoreTools::ContainerAdapter<T, N>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (N <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("index索引越界"))
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return elements[index];

#include SYSTEM_WARNING_POP
}

template <typename T, int N>
requires(N > 0) T& CoreTools::ContainerAdapter<T, N>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::iterator CoreTools::ContainerAdapter<T, N>::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, 0 };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, 0 };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::iterator CoreTools::ContainerAdapter<T, N>::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, N };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, N };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::reverse_iterator CoreTools::ContainerAdapter<T, N>::rbegin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator{ end() };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::rbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator{ end() };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::reverse_iterator CoreTools::ContainerAdapter<T, N>::rend() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator{ begin() };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::rend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator{ begin() };
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::cbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return begin();
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::cend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return end();
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::crbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rbegin();
}

template <typename T, int N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::crend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rend();
}

template <typename T, int N>
requires(N > 0) void CoreTools::ContainerAdapter<T, N>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    std::fill(begin(), end(), value);
}

template <typename T>
CoreTools::ContainerAdapter<T>::ContainerAdapter(T* elements, int numElements)
    : numElements{ numElements }, elements{ elements }
{
    if (numElements <= 0 || elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的元素状态。"))
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ContainerAdapter<T>::IsValid() const noexcept
{
    if (0 < numElements && elements != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int CoreTools::ContainerAdapter<T>::size() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return numElements;
}

template <typename T>
T* CoreTools::ContainerAdapter<T>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T>
const T* CoreTools::ContainerAdapter<T>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return elements;
}

template <typename T>
const T& CoreTools::ContainerAdapter<T>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (numElements <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("index索引越界"));
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return elements[index];

#include SYSTEM_WARNING_POP
}

template <typename T>
T& CoreTools::ContainerAdapter<T>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::iterator CoreTools::ContainerAdapter<T>::begin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, 0 };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, 0 };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::iterator CoreTools::ContainerAdapter<T>::end() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, numElements };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, numElements };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::reverse_iterator CoreTools::ContainerAdapter<T>::rbegin() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator(end());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::rbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator(end());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::reverse_iterator CoreTools::ContainerAdapter<T>::rend() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator(begin());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::rend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator(begin());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::cbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return begin();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::cend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return end();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::crbegin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rbegin();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::crend() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rend();
}

template <typename T>
void CoreTools::ContainerAdapter<T>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    for (auto i = 0; i < numElements; ++i)
    {
        elements[i] = value;
    }
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
