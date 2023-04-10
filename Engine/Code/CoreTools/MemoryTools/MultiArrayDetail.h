///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 15:45)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H

#include "MultiArray.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, bool OrderLToR, size_t... Sizes>
CoreTools::MultiArray<T, OrderLToR, Sizes...>::MultiArray() noexcept
    : ParentType{}, container{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, size_t... Sizes>
bool CoreTools::MultiArray<T, OrderLToR, Sizes...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, size_t... Sizes>
const T* CoreTools::MultiArray<T, OrderLToR, Sizes...>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR, size_t... Sizes>
T* CoreTools::MultiArray<T, OrderLToR, Sizes...>::data() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.data();
}

template <typename T, bool OrderLToR, size_t... Sizes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator[](size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <typename T, bool OrderLToR, size_t... Sizes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator[](size_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR, size_t... Sizes>
void CoreTools::MultiArray<T, OrderLToR, Sizes...>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.fill(value);
}

template <typename T, bool OrderLToR, size_t... Sizes>
template <typename... IndexTypes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR, size_t... Sizes>
template <typename... IndexTypes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR, size_t... Sizes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR, size_t... Sizes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(const std::array<size_t, sizeof...(Sizes)>& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR, size_t... Sizes>
std::strong_ordering CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator<=>(const MultiArray& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container <=> rhs.container;
}

template <typename T, bool OrderLToR>
CoreTools::MultiArray<T, OrderLToR>::MultiArray() noexcept
    : ParentType{}, container{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, bool OrderLToR>
CoreTools::MultiArray<T, OrderLToR>::MultiArray(const SizeType& sizes)
    : ParentType{ sizes }, container{}
{
    container.resize(this->GetSize());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, bool OrderLToR>
CoreTools::MultiArray<T, OrderLToR>::MultiArray(const std::initializer_list<size_t>& sizes)
    : ParentType{ sizes }, container{}
{
    container.resize(this->GetSize());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename T, bool OrderLToR>
bool CoreTools::MultiArray<T, OrderLToR>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR>
void CoreTools::MultiArray<T, OrderLToR>::Reset(const SizeType& sizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ParentType::Reset(sizes);
    container.resize(this->GetSize());
}

template <typename T, bool OrderLToR>
void CoreTools::MultiArray<T, OrderLToR>::Reset(const std::initializer_list<size_t>& sizes)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    ParentType::Reset(sizes);
    container.resize(this->GetSize());
}

template <typename T, bool OrderLToR>
const T* CoreTools::MultiArray<T, OrderLToR>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.data();
}

template <typename T, bool OrderLToR>
T* CoreTools::MultiArray<T, OrderLToR>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArray<T, OrderLToR>::operator[](size_t index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArray<T, OrderLToR>::operator[](size_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR>
void CoreTools::MultiArray<T, OrderLToR>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::fill(container.begin(), container.end(), value);
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
const T& CoreTools::MultiArray<T, OrderLToR>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR>
template <typename... IndexTypes>
T& CoreTools::MultiArray<T, OrderLToR>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR>
const T& CoreTools::MultiArray<T, OrderLToR>::operator()(const SizeType& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArray<T, OrderLToR>::operator()(const SizeType& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR>
std::strong_ordering CoreTools::MultiArray<T, OrderLToR>::operator<=>(const MultiArray& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto result = ParentType::operator<=>(rhs);

    if (result != std::weak_ordering::equivalent)
    {
        return result;
    }
    else
    {
        return container <=> rhs.container;
    }
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H
