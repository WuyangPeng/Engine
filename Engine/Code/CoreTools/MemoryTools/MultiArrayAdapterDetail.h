///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 16:13)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H

#include "MultiArrayAdapter.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, bool OrderLToR, size_t... Sizes>
CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::MultiArrayAdapter(T* container)
    : container{ container }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, size_t... Sizes>
bool CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, size_t... Sizes>
void CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::Reset(T* aContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (aContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    container = aContainer;
}

template <typename T, bool OrderLToR, size_t... Sizes>
const T* CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container;
}

template <typename T, bool OrderLToR, size_t... Sizes>
T* CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR, size_t... Sizes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator[](size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (this->GetSize() <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引无效。"));
    }

    return container[index];
}

template <typename T, bool OrderLToR, size_t... Sizes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator[](size_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR, size_t... Sizes>
void CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto i = 0u; i < this->GetSize(); ++i)
    {
        container[i] = value;
    }
}

template <typename T, bool OrderLToR, size_t... Sizes>
template <typename... IndexTypes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(tuple...)];
}

template <typename T, bool OrderLToR, size_t... Sizes>
template <typename... IndexTypes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container[this->GetIndex(tuple...)];
}

template <typename T, bool OrderLToR, size_t... Sizes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(coordinate)];
}

template <typename T, bool OrderLToR, size_t... Sizes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container[this->GetIndex(coordinate)];
}

template <typename T, bool OrderLToR, size_t... Sizes>
std::strong_ordering CoreTools::MultiArrayAdapter<T, OrderLToR, Sizes...>::operator<=>(const MultiArrayAdapter& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (container == nullptr && rhs.container == nullptr)
    {
        return std::strong_ordering::equivalent;
    }
    else if (container == nullptr && rhs.container != nullptr)
    {
        return std::strong_ordering::less;
    }
    else if (container != nullptr && rhs.container == nullptr)
    {
        return std::strong_ordering::greater;
    }
    else
    {
        for (size_t i = 0; i < this->GetSize() && i < rhs->GetSize(); ++i)
        {
            const auto result = container[i] <=> rhs.container[i];
            if (result != std::strong_ordering::equivalent)
            {
                return result;
            }
        }

        return this->GetSize() <=> rhs->GetSize();
    }
}

template <typename T, bool OrderLToR>
CoreTools::MultiArrayAdapter<T, OrderLToR>::MultiArrayAdapter() noexcept
    : ParentType{}, container{ nullptr }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, bool OrderLToR>
CoreTools::MultiArrayAdapter<T, OrderLToR>::MultiArrayAdapter(const SizeType& sizes, T* container)
    : ParentType{ sizes }, container{ container }
{
    if (container == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR>
bool CoreTools::MultiArrayAdapter<T, OrderLToR>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR>
void CoreTools::MultiArrayAdapter<T, OrderLToR>::Reset(const SizeType& sizes, T* aContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (aContainer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器必须存在。"));
    }

    ParentType::Reset(sizes);
    container = aContainer;
}

template <typename T, bool OrderLToR>
const T* CoreTools::MultiArrayAdapter<T, OrderLToR>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container;
}

template <typename T, bool OrderLToR>
T* CoreTools::MultiArrayAdapter<T, OrderLToR>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator[](size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (this->GetSize() <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引无效。"));
    }

    return container[index];
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator[](size_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR>
void CoreTools::MultiArrayAdapter<T, OrderLToR>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto i = 0u; i < this->GetSize(); ++i)
    {
        container[i] = value;
    }
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(tuple...)];
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container[this->GetIndex(tuple...)];
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container[this->GetIndex(coordinate)];
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArrayAdapter<T, OrderLToR>::operator()(const SizeType& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container[this->GetIndex(coordinate)];
}

template <typename T, bool OrderLToR>
std::strong_ordering CoreTools::MultiArrayAdapter<T, OrderLToR>::operator<=>(const MultiArrayAdapter& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (container == nullptr && rhs.container == nullptr)
    {
        return std::strong_ordering::equivalent;
    }
    else if (container == nullptr && rhs.container != nullptr)
    {
        return std::strong_ordering::less;
    }
    else if (container != nullptr && rhs.container == nullptr)
    {
        return std::strong_ordering::greater;
    }
    else
    {
        for (size_t i = 0; i < this->GetSize() && i < rhs->GetSize(); ++i)
        {
            const auto result = container[i] <=> rhs.container[i];
            if (result != std::strong_ordering::equivalent)
            {
                return result;
            }
        }

        return this->GetSize() <=> rhs->GetSize();
    }
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_DETAIL_H
