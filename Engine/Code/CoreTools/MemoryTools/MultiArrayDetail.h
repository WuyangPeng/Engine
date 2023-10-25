///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:33)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H

#include "LatticeDetail.h"
#include "MultiArray.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T, bool OrderLToR, int... Sizes>
CoreTools::MultiArray<T, OrderLToR, Sizes...>::MultiArray() noexcept
    : ParentType{}, container{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArray<T, OrderLToR, Sizes...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, bool OrderLToR, int... Sizes>
const T* CoreTools::MultiArray<T, OrderLToR, Sizes...>::GetData() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetData);
}

template <typename T, bool OrderLToR, int... Sizes>
T* CoreTools::MultiArray<T, OrderLToR, Sizes...>::GetData() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.data();
}

template <typename T, bool OrderLToR, int... Sizes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <typename T, bool OrderLToR, int... Sizes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator[](int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T, bool OrderLToR, int... Sizes>
void CoreTools::MultiArray<T, OrderLToR, Sizes...>::Fill(const T& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    container.fill(value);
}

template <typename T, bool OrderLToR, int... Sizes>
template <typename... IndexTypes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR, int... Sizes>
template <typename... IndexTypes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(IndexTypes... tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(tuple...));
}

template <typename T, bool OrderLToR, int... Sizes>
const T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR, int... Sizes>
T& CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator()(const std::array<int, sizeof...(Sizes)>& coordinate)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return container.at(this->GetIndex(coordinate));
}

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator==(const MultiArray& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container == rhs.container;
}

template <typename T, bool OrderLToR, int... Sizes>
bool CoreTools::MultiArray<T, OrderLToR, Sizes...>::operator<(const MultiArray& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container < rhs.container;
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
CoreTools::MultiArray<T, OrderLToR>::MultiArray(const std::initializer_list<int>& sizes)
    : ParentType{ sizes }, container{}
{
    container.resize(this->GetSize());

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

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
void CoreTools::MultiArray<T, OrderLToR>::Reset(const std::initializer_list<int>& sizes)
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
const T& CoreTools::MultiArray<T, OrderLToR>::operator[](int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return container.at(index);
}

template <typename T, bool OrderLToR>
T& CoreTools::MultiArray<T, OrderLToR>::operator[](int index)
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
bool CoreTools::MultiArray<T, OrderLToR>::operator==(const MultiArray& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ParentType::operator==(rhs) && container == rhs.container;
}

template <typename T, bool OrderLToR>
bool CoreTools::MultiArray<T, OrderLToR>::operator<(const MultiArray& rhs) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (ParentType::operator==(rhs))
    {
        return container < rhs.container;
    }

    return ParentType::operator<(rhs);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_DETAIL_H
