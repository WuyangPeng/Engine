///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_DETAIL_H

#include "ContainerAdapter.h"
#include "RawIteratorsDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, size_t N>
requires(N > 0) CoreTools::ContainerAdapter<T, N>::ContainerAdapter(T* elements, size_t numElements)
    : elements{ elements }
{
    System::UnusedFunction(numElements);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, size_t N>
requires(N > 0) bool CoreTools::ContainerAdapter<T, N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, size_t N>
requires(N > 0) void CoreTools::ContainerAdapter<T, N>::Reset(T* aElements, size_t numElements) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(numElements);

    elements = aElements;
}

template <typename T, size_t N>
requires(N > 0) T* CoreTools::ContainerAdapter<T, N>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, size_t N>
requires(N > 0) const T* CoreTools::ContainerAdapter<T, N>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return elements;
}

template <typename T, size_t N>
requires(N > 0) const T& CoreTools::ContainerAdapter<T, N>::operator[](size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    if (N <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("index索引越界"));
    }

    return elements[index];
}

template <typename T, size_t N>
requires(N > 0) T& CoreTools::ContainerAdapter<T, N>::operator[](size_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::iterator CoreTools::ContainerAdapter<T, N>::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return iterator{ elements, 0 };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::begin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return const_iterator{ elements, 0 };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::iterator CoreTools::ContainerAdapter<T, N>::end()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return iterator{ elements, N };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::end() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return const_iterator{ elements, N };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::reverse_iterator CoreTools::ContainerAdapter<T, N>::rbegin()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return reverse_iterator{ end() };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::rbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return const_reverse_iterator{ end() };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::reverse_iterator CoreTools::ContainerAdapter<T, N>::rend()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return reverse_iterator{ begin() };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::rend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return const_reverse_iterator{ begin() };
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::cbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return begin();
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_iterator CoreTools::ContainerAdapter<T, N>::cend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return end();
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::crbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return rbegin();
}

template <typename T, size_t N>
requires(N > 0) typename CoreTools::ContainerAdapter<T, N>::const_reverse_iterator CoreTools::ContainerAdapter<T, N>::crend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    return rend();
}

template <typename T, size_t N>
requires(N > 0) void CoreTools::ContainerAdapter<T, N>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    std::fill(begin(), end(), value);
}

template <typename T>
CoreTools::ContainerAdapter<T>::ContainerAdapter(T* elements, size_t numElements)
    : numElements{ numElements }, elements{ elements }
{
    if (numElements <= 0 && elements != nullptr ||
        0 < numElements && elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的元素状态。"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool CoreTools::ContainerAdapter<T>::IsValid() const noexcept
{
    if (0 < numElements && elements != nullptr)
        return true;
    else if (numElements <= 0 && elements == nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void CoreTools::ContainerAdapter<T>::Reset(T* aElements, size_t aNumElements)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (aNumElements <= 0 && aElements != nullptr ||
        0 < aNumElements && aElements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的元素状态。"));
    }

    numElements = aNumElements;
    elements = aElements;
}

template <typename T>
size_t CoreTools::ContainerAdapter<T>::GetSize() const noexcept
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
const T& CoreTools::ContainerAdapter<T>::operator[](size_t index) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (elements == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("elements 指针为空。"));
    }

    if (numElements <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("index索引越界"));
    }

    return elements[index];
}

template <typename T>
T& CoreTools::ContainerAdapter<T>::operator[](size_t index) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::iterator CoreTools::ContainerAdapter<T>::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, 0 };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::begin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, 0 };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::iterator CoreTools::ContainerAdapter<T>::end()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return iterator{ elements, numElements };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::end() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_iterator{ elements, numElements };
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::reverse_iterator CoreTools::ContainerAdapter<T>::rbegin()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator(end());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::rbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator(end());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::reverse_iterator CoreTools::ContainerAdapter<T>::rend()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return reverse_iterator(begin());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::rend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return const_reverse_iterator(begin());
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::cbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return begin();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_iterator CoreTools::ContainerAdapter<T>::cend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return end();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::crbegin() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rbegin();
}

template <typename T>
typename CoreTools::ContainerAdapter<T>::const_reverse_iterator CoreTools::ContainerAdapter<T>::crend() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return rend();
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_DETAIL_H
